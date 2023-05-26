#include <AnimationWindow.h>
#include <widgets/Button.h>
#include <filesystem>
#include <list>
#include <optional>
#include <type_traits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <cassert>
#include "Tasks.h"

#define GAME 0
#define DRAW_TEST_QUAD 0

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 768
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 480
#endif

template <typename T> inline constexpr
T sgn(T val) {
    return (val > 0) - (val < 0);
}

int main() {

    auto tile_pool = TileLoader::load("tiles/tile_info");


    Level lvl;

    try {
        lvl = LevelLoader::load("./level_save");
    } catch ( std::runtime_error &err )
    {
        std::cerr << err.what() << "\n";
    }

    TDT4102::AnimationWindow window(50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, "4102Game");
    Context ctx(&window, std::make_shared<Camera>());

    CameraController camController{1};

    ctx.getCamera().focusOn({0,0}, window.width(), window.height() );

    bool lmb_held = false;

    Player player{"sprites/character.png"};
    player.set_position({0,0});

    // -----------------------------------------------------
    // -------------------- GUI ELEMENTS -------------------
    // -----------------------------------------------------
    LevelRenderer renderer(ctx, lvl, tile_pool);


    auto key_pair = Locksmith::make_door({23,12});

    std::list<DoorKeyEntity> keys{};
    keys.emplace_back(DoorKeyEntity(std::move(key_pair.second), TDT4102::Point{5,5}, TDT4102::Color{255,0,0,255}));

    key_pair = Locksmith::make_door({19,25});
    keys.emplace_back(DoorKeyEntity(std::move(key_pair.second), TDT4102::Point{18,19}, TDT4102::Color::gold));

    WalkableOverlay overlay(lvl);

    OverlayButton overlay_button{};

    window.add(overlay_button);

    while (!window.should_close()) {

        // ------------------------------------------------------------
        // HANDLE INPUT
        // ------------------------------------------------------------
        auto hovered_tile = CoordinateSystem::to_grid(ctx, window.get_mouse_coordinates());

        bool is_lmb_down     = window.is_left_mouse_button_down();
        bool nothing_clicked = ! is_lmb_down && ! lmb_held;
        bool initial_click   =   is_lmb_down && ! lmb_held;
        bool released        = ! is_lmb_down &&   lmb_held;

        if ( nothing_clicked) {
        }

        if ( initial_click ) {
            player.moveTo(hovered_tile, lvl);
            std::cout << "Clicked " << hovered_tile << "\n";
        }

        if ( lmb_held && ! initial_click ) {
        }

        if ( released ) {
        }


        lmb_held = window.is_left_mouse_button_down();

        camController.handleInput(ctx);

        player.handle_keyboard_input(window, lvl);

        window.next_frame();


        // ------------------------------------------------------------
        // RENDER
        // ------------------------------------------------------------
        renderer.render();

        if ( show_walkable_overlay )
            overlay.render(ctx);

        player.draw(ctx);

        for ( DoorKeyEntity &key : keys ) {
            key.draw(ctx);
        }

        // Unlocking doors
        auto &player_keys = player.get_keys();

        for ( size_t i = 0; i < player_keys.size(); i++ )
        {
            player_keys[i].draw_static(ctx, {static_cast<int>(30*i), 5});

            auto &doorKeyEntity = player_keys[i];
            auto door = (doorKeyEntity.get_key_ref()).getDoor();
            auto door_position = door->get_position();

            if ( chebyshev_distance(player.position, door_position ) < 2 )
            {
                door->unlock();
                lvl.set_walkable_at(door_position, true);
                lvl.set_tile_at(door_position, 50);
            }
        }

        // Picking up Keys
        decltype(keys.begin()) erase_index = keys.end();

        for ( auto it = keys.begin(); it != keys.end(); it++ )
        {
            DoorKeyEntity &key = *it;
            if ( key.get_position() == player.position ) {
                player.pick_up_key(std::move(key));
                erase_index =  it;
            }
        }

        if ( erase_index != keys.end() )
            keys.erase(erase_index);

        TDT4102::Color hover_color;

        if ( player.canMoveTo(hovered_tile, lvl) ) {
            hover_color = TDT4102::Color{255,255,255,255};
        } else {
            hover_color = TDT4102::Color{255,0,0,255};
        }
        QuadRenderer::render(ctx, CoordinateSystem::to_screen(ctx, hovered_tile) + TDT4102::Point{0, TILE_WIDTH}, hover_color);

    }

    return 0;
}

