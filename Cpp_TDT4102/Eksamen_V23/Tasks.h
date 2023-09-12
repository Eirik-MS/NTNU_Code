#ifndef TASKS_H_8CO6EFC9
#define TASKS_H_8CO6EFC9

#include <AnimationWindow.h>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <utility>
#include <vector>
#include <widgets/Button.h>


class OverlayButton;
class CameraController;
class Camera;
class Context;
class Door;
class DoorKey;
class DoorKeyEntity;
class Locksmith;
class DoorKeyRenderer;
class Entity;
class Level;
class LevelLoader;
class TileRenderer;
class QuadRenderer;
class LevelRenderer;
class PlacementOverlay;
class WalkableOverlay;
class Player;
class TilePool;
class TileLoader;
struct CoordinateSystem;
struct PlayerControllable;
struct Tile;
struct TileDescriptor;


static constexpr int EMPTY_TILE_ID = -1;

static constexpr int WORLD_WIDTH  = 6;
static constexpr int WORLD_HEIGHT = 6;


constexpr static int TILE_SIZE = 64;

constexpr static int TILE_WIDTH = TILE_SIZE / 2;
constexpr static int TILE_HEIGHT = TILE_SIZE / 4;


static bool show_walkable_overlay = false;


TDT4102::Point operator+(const TDT4102::Point p1, const TDT4102::Point p2);
TDT4102::Point operator-(const TDT4102::Point p1, const TDT4102::Point p2);
TDT4102::Point operator-(const TDT4102::Point &p1);

int chebyshev_distance(TDT4102::Point p1, TDT4102::Point p2);

std::ostream &operator<<(std::ostream &stream, const TDT4102::Point &point);

bool operator==(const TDT4102::Point first, const TDT4102::Point second);

class OverlayButton : public TDT4102::Button
{
public:
    OverlayButton() : TDT4102::Button(OverlayButton::render_location, 100, 40, "Overlay") {
        setCallback(OverlayButton::callback);
    }

    static void callback() {
        show_walkable_overlay = ! show_walkable_overlay;
    }

private:
    static constexpr TDT4102::Point render_location{5, 50};
};



class Entity
{
public:
    virtual ~Entity() {}
    virtual void draw(Context &ctx) = 0;
    virtual void draw_static(Context &ctx, TDT4102::Point coordinate) = 0;
    virtual void set_position(TDT4102::Point) = 0;
    virtual TDT4102::Point get_position() const noexcept = 0;
};


class CameraController {
public:
    CameraController(int speed);

    void setScrollSpeed(int speed) noexcept;

    void handleInput(Context &ctx);

private:
    int m_scrollSpeed = 1;
};


struct Tile
{
    Tile(int id, bool walkable, const std::filesystem::path tile_image_path);

    Tile(const Tile &other);
    Tile &operator=(const Tile &other);

    Tile(Tile &&rhs);
    Tile &operator=(Tile &&rhs);

    bool has_image() const noexcept;


    int id;
    bool walkable;
    std::shared_ptr<TDT4102::Image> image;
};

class TilePool
{
public:
    using KeyType = int;
    // static TilePool &getInstance();
    //

    std::optional<Tile> get_tile(KeyType key);

    const std::vector<int> &get_tile_ids() const;

    bool add_tile(const KeyType &key, Tile tile);

private:
    std::unordered_map<KeyType, Tile> tile_pool;
    std::vector<int> tile_ids;

    friend class TileLoader;
};



struct TileDescriptor
{
    int id;
    std::string filename;
    bool walkable;
};


TileDescriptor &operator>>(std::istream &ss, TileDescriptor &rhs);

class TileLoader
{
public:
    static TilePool load(const std::filesystem::path descriptor_file_path);
    static TileDescriptor process_line(std::string line);

private:
    TileLoader() = delete;
};




/*! \class Camera
 *  \brief Handles panning around by giving offset vectors.
 *
 *  TODO: Detailed description
 */
class Camera
{
public:
    Camera();
    explicit Camera(TDT4102::Point initialPoint);

    void focusOn(TDT4102::Point focus, int screenWidth, int screenHeight) noexcept;

    void translateX(int delta) noexcept;
    void translateY(int delta) noexcept;

    const TDT4102::Point getPosition() const noexcept;
    const TDT4102::Point getCorrectionVector() const noexcept;

    const std::array<float, 4> &getProjectionMatrix() const noexcept;

    const std::array<float, 4> &getInverseProjectionMatrix() const noexcept;


protected:
    TDT4102::Point position;

    static constexpr std::array<float, 4> projMatrix = {
        TILE_WIDTH, -TILE_WIDTH,
        TILE_HEIGHT, TILE_HEIGHT
    };


    static constexpr std::array<float, 4> inv_projMatrix = [](){

        float w = 1.0f / (2.0f * static_cast<float>(TILE_WIDTH));
        float h = 1.0f / (2.0f * static_cast<float>(TILE_HEIGHT));

        return std::array<float, 4>{
              w, h,
            - w, h};
    }();
};











/*! \class Context
 *  \brief Brief class description
 *
 *  Detailed description
 */

class Context
{
public:
    Context(TDT4102::AnimationWindow *window, std::shared_ptr<Camera> cam);

    Camera &getCamera() noexcept;

    const Camera &getCamera() const noexcept;

    TDT4102::AnimationWindow &getWindow() noexcept;

    const TDT4102::AnimationWindow &getWindow() const noexcept;

private:
    std::shared_ptr<Camera> cam;

    // BE CAREFUL, the lifetime of the context should be contained within that of the AnimationWindow
    TDT4102::AnimationWindow *window;
};


TDT4102::Point matmul2(const std::array<float, 4> &matrix, TDT4102::Point point);

class Door
{
public:
    Door() = delete;
    Door (TDT4102::Point _position);

    bool is_locked() const noexcept;

    const TDT4102::Point get_position() const noexcept;

    void unlock() noexcept;

private:

    TDT4102::Point position;
    bool locked{true};


    friend class Locksmith;
};

class DoorKey
{
public:
    /// `getDoor()`
    /// Gets the `Door` associated with this `DoorKey`
    std::shared_ptr<Door> getDoor();

private:

    std::shared_ptr<Door> associated_door;

    ///
    DoorKey(std::shared_ptr<Door> door);

    DoorKey(const DoorKey &other);

    DoorKey(DoorKey &&other) = delete;

    friend class Locksmith;
};


class DoorKeyEntity : public Entity
{
public:
    DoorKeyEntity() = delete;
    DoorKeyEntity(
            std::unique_ptr<DoorKey> _key,
            TDT4102::Point _position,
            TDT4102::Color _color)
        : key{std::move(_key)}, position{_position}, color{_color}
    { }

    virtual TDT4102::Point get_position() const noexcept override;
    virtual void set_position(TDT4102::Point _position) override;

    std::unique_ptr<DoorKey> get_key() ;
    DoorKey &get_key_ref();
    TDT4102::Color get_color() const noexcept;

    virtual void draw(Context &ctx) override;
    virtual void draw_static(Context &ctx, TDT4102::Point coordinate) override;

private:
    /// The aggregation, holding the Key this Entity is responsible for.
    std::unique_ptr<DoorKey> key;
    TDT4102::Point position;
    TDT4102::Color color;
};


class Locksmith
{
public:
    /// Creates an associated pair of `Door` and `DoorKey`.
    static std::pair<std::shared_ptr<Door>, std::unique_ptr<DoorKey>>
        make_door(TDT4102::Point position);

};


class DoorKeyRenderer
{
public:
    static void render(TDT4102::AnimationWindow &window, TDT4102::Point position, TDT4102::Color color)
    {
        window.draw_arc(position + TDT4102::Point{10,10}, 8, 8, 0, 360, color);
        window.draw_arc(position + TDT4102::Point{10,10}, 7, 7, 0, 360, color);
        window.draw_arc(position + TDT4102::Point{10,10}, 6, 6, 0, 360, color);

        window.draw_line(position + TDT4102::Point{10, 18}, position + TDT4102::Point{10, 36}, color);
        window.draw_line(position + TDT4102::Point{11, 18}, position + TDT4102::Point{11, 36}, color);
        window.draw_line(position + TDT4102::Point{12, 18}, position + TDT4102::Point{12, 36}, color);
        window.draw_line(position + TDT4102::Point{9, 18}, position + TDT4102::Point{9, 36}, color);
        window.draw_line(position + TDT4102::Point{9, 18}, position + TDT4102::Point{9, 36}, color);
        window.draw_line(position + TDT4102::Point{8, 18}, position + TDT4102::Point{8, 36}, color);

        window.draw_line(position + TDT4102::Point{8, 36}, position + TDT4102::Point{17, 36}, color);
        window.draw_line(position + TDT4102::Point{8, 35}, position + TDT4102::Point{17, 35}, color);
        window.draw_line(position + TDT4102::Point{8, 34}, position + TDT4102::Point{17, 34}, color);


        window.draw_line(position + TDT4102::Point{8, 30}, position + TDT4102::Point{15, 30}, color);
        window.draw_line(position + TDT4102::Point{8, 29}, position + TDT4102::Point{15, 29}, color);
        window.draw_line(position + TDT4102::Point{8, 28}, position + TDT4102::Point{15, 28}, color);
    }
};









class Level
{
public:
    Level();
    Level(unsigned int _width, unsigned int _height) : width{_width}, height{_height} {
        tiles.resize(width * height, -1);
        walkable.resize(width * height, false);
    }

    bool is_walkable(const TDT4102::Point coordinate) const;
    int tile_at(const TDT4102::Point coordinate) const;
    void set_tile_at(const TDT4102::Point coordinate, const int tile);
    void set_walkable_at(const TDT4102::Point coordinate, const bool walkable);

    unsigned int get_width() const noexcept;
    unsigned int get_height() const noexcept;

private:
    unsigned int width = 1;
    unsigned int height = 1;

    std::vector<int> tiles = {0};
    std::vector<bool> walkable = {false};

    friend class LevelLoader;
};




class LevelLoader {
public:
    static Level load(std::filesystem::path path);

    template <typename T, T DEFAULT_VALUE, template <typename U, typename Allocator = std::allocator<U>> typename Container>
    static void read_block(std::ifstream &file_stream, Container<T> &target);


private:
    LevelLoader();
};




size_t integer_pairing(unsigned int x, unsigned int y);

class TileRenderer
{
public:
    static void render(Context &ctx, const Tile &tile, TDT4102::Point anchor);
};

class QuadRenderer
{
public:
    static void render(Context &ctx, TDT4102::Point anchor, TDT4102::Color color);
};

struct CoordinateSystem {
    static TDT4102::Point to_screen(const Context &ctx, TDT4102::Point grid_point);
    static TDT4102::Point to_grid(const Context &ctx, TDT4102::Point screen_coordinate);
};

class LevelRenderer
{
public:
    LevelRenderer(Context &ctx, Level &lvl, TilePool &pool);

    void render() const;

private:
    Context &ctx;
    Level &lvl;
    TilePool &pool;

};

class PlacementOverlay {
public:
    PlacementOverlay(Context &ctx);

    void reset_tile();

    void render();

    void set_begin(TDT4102::Point _begin);
    void set_end(TDT4102::Point _end);

    void set_tile(Tile _tile);
    void set_tile(std::optional<Tile> _tile);

private:
    Context &ctx;

    Tile active_tile{-1, false, ""};

    TDT4102::Point begin;
    TDT4102::Point end;
};

class WalkableOverlay {
public:
    WalkableOverlay(const Level &lvl);

    void render(Context &ctx);
private:
    const Level &lvl;
};









struct PlayerControllable
{
    TDT4102::Point position;

    int max_move_length = 1;

    bool canMoveTo(TDT4102::Point new_position, const Level &lvl);

    void moveTo(TDT4102::Point new_position, const Level &lvl);
};

class Player : public PlayerControllable, public Entity
{
public:

    Player() = delete;

    explicit Player(std::filesystem::path spritePath);

    virtual void draw(Context &ctx) override;

    virtual void draw_static(Context &ctx, TDT4102::Point coordinate) override;
    virtual void set_position(TDT4102::Point) override;
    virtual TDT4102::Point get_position() const noexcept override;

    void handle_keyboard_input(TDT4102::AnimationWindow &window, const Level &lvl);

    void pick_up_key(DoorKeyEntity &&key);

    std::vector<DoorKeyEntity> &get_keys();

private:
    TDT4102::Image sprite;
    bool movement_keys[4]{false};

    std::vector<DoorKeyEntity> key_inventory{};

};



#endif /* end of include guard: TASKS_H_8CO6EFC9 */

