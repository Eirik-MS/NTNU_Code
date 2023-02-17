{
  "version": "1.2",
  "package": {
    "name": "3-bit MUX",
    "version": "",
    "description": "",
    "author": "",
    "image": ""
  },
  "design": {
    "board": "icezum",
    "graph": {
      "blocks": [
        {
          "id": "cf44d3c9-6870-4424-ab49-77d452d07454",
          "type": "basic.input",
          "data": {
            "name": "C",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 256,
            "y": 208
          }
        },
        {
          "id": "7724b397-83dc-4771-81f0-8d1686bc11b1",
          "type": "basic.input",
          "data": {
            "name": "A1",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 128,
            "y": 344
          }
        },
        {
          "id": "20ba284a-6a58-4db2-a224-e7be5f74717f",
          "type": "basic.output",
          "data": {
            "name": "q1",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ]
          },
          "position": {
            "x": 640,
            "y": 376
          }
        },
        {
          "id": "d1074d32-f063-4817-bfcf-1c46a54eb2b3",
          "type": "basic.input",
          "data": {
            "name": "B1",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 128,
            "y": 416
          }
        },
        {
          "id": "1b3688b3-d5e8-4ddb-854c-b14faa0e07e0",
          "type": "basic.input",
          "data": {
            "name": "A2",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 120,
            "y": 520
          }
        },
        {
          "id": "100ebdff-c571-4fd5-b8f8-7b497486687c",
          "type": "basic.output",
          "data": {
            "name": "q2",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ]
          },
          "position": {
            "x": 648,
            "y": 552
          }
        },
        {
          "id": "60713013-1ca4-4a4c-92f0-49587c0c6870",
          "type": "basic.input",
          "data": {
            "name": "B2",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 120,
            "y": 592
          }
        },
        {
          "id": "916babfd-269f-4e5f-96b9-cb93d3b9c68a",
          "type": "basic.input",
          "data": {
            "name": "A3",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 128,
            "y": 672
          }
        },
        {
          "id": "d5e0ec3b-96d3-44cf-a89a-44e646f6e8ce",
          "type": "basic.output",
          "data": {
            "name": "q3",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ]
          },
          "position": {
            "x": 648,
            "y": 704
          }
        },
        {
          "id": "ecb1424d-526e-4ced-8417-a6ce36a9062f",
          "type": "basic.input",
          "data": {
            "name": "B3",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "NULL",
                "value": "NULL"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 128,
            "y": 744
          }
        },
        {
          "id": "e4af3711-fee4-49f3-b959-5d00a8bdc9b6",
          "type": "2d00dc6cbf770622c583a0dff0e0d8e2763ab2ec",
          "position": {
            "x": 424,
            "y": 360
          },
          "size": {
            "width": 96,
            "height": 96
          }
        },
        {
          "id": "e1b4b5d7-3eec-4199-a10a-ab337f082063",
          "type": "2d00dc6cbf770622c583a0dff0e0d8e2763ab2ec",
          "position": {
            "x": 432,
            "y": 536
          },
          "size": {
            "width": 96,
            "height": 96
          }
        },
        {
          "id": "eae70424-e02c-46ef-a0e5-ae7cad6a252a",
          "type": "2d00dc6cbf770622c583a0dff0e0d8e2763ab2ec",
          "position": {
            "x": 432,
            "y": 688
          },
          "size": {
            "width": 96,
            "height": 96
          }
        }
      ],
      "wires": [
        {
          "source": {
            "block": "7724b397-83dc-4771-81f0-8d1686bc11b1",
            "port": "out"
          },
          "target": {
            "block": "e4af3711-fee4-49f3-b959-5d00a8bdc9b6",
            "port": "c3f73f68-1074-4355-b69f-6a20f7bea3e7"
          }
        },
        {
          "source": {
            "block": "1b3688b3-d5e8-4ddb-854c-b14faa0e07e0",
            "port": "out"
          },
          "target": {
            "block": "e1b4b5d7-3eec-4199-a10a-ab337f082063",
            "port": "c3f73f68-1074-4355-b69f-6a20f7bea3e7"
          }
        },
        {
          "source": {
            "block": "916babfd-269f-4e5f-96b9-cb93d3b9c68a",
            "port": "out"
          },
          "target": {
            "block": "eae70424-e02c-46ef-a0e5-ae7cad6a252a",
            "port": "c3f73f68-1074-4355-b69f-6a20f7bea3e7"
          }
        },
        {
          "source": {
            "block": "ecb1424d-526e-4ced-8417-a6ce36a9062f",
            "port": "out"
          },
          "target": {
            "block": "eae70424-e02c-46ef-a0e5-ae7cad6a252a",
            "port": "5fb29465-2ee7-45bb-afa4-9a3de895c774"
          },
          "vertices": [
            {
              "x": 256,
              "y": 744
            }
          ]
        },
        {
          "source": {
            "block": "60713013-1ca4-4a4c-92f0-49587c0c6870",
            "port": "out"
          },
          "target": {
            "block": "e1b4b5d7-3eec-4199-a10a-ab337f082063",
            "port": "5fb29465-2ee7-45bb-afa4-9a3de895c774"
          },
          "vertices": [
            {
              "x": 248,
              "y": 592
            }
          ]
        },
        {
          "source": {
            "block": "d1074d32-f063-4817-bfcf-1c46a54eb2b3",
            "port": "out"
          },
          "target": {
            "block": "e4af3711-fee4-49f3-b959-5d00a8bdc9b6",
            "port": "5fb29465-2ee7-45bb-afa4-9a3de895c774"
          },
          "vertices": [
            {
              "x": 256,
              "y": 416
            }
          ]
        },
        {
          "source": {
            "block": "cf44d3c9-6870-4424-ab49-77d452d07454",
            "port": "out"
          },
          "target": {
            "block": "e4af3711-fee4-49f3-b959-5d00a8bdc9b6",
            "port": "67ed5e09-486d-4f97-929f-aefea9c43951"
          }
        },
        {
          "source": {
            "block": "cf44d3c9-6870-4424-ab49-77d452d07454",
            "port": "out"
          },
          "target": {
            "block": "e1b4b5d7-3eec-4199-a10a-ab337f082063",
            "port": "67ed5e09-486d-4f97-929f-aefea9c43951"
          }
        },
        {
          "source": {
            "block": "cf44d3c9-6870-4424-ab49-77d452d07454",
            "port": "out"
          },
          "target": {
            "block": "eae70424-e02c-46ef-a0e5-ae7cad6a252a",
            "port": "67ed5e09-486d-4f97-929f-aefea9c43951"
          }
        },
        {
          "source": {
            "block": "eae70424-e02c-46ef-a0e5-ae7cad6a252a",
            "port": "061aa997-2f30-4591-8841-fb6abf5c3b2e"
          },
          "target": {
            "block": "d5e0ec3b-96d3-44cf-a89a-44e646f6e8ce",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "e1b4b5d7-3eec-4199-a10a-ab337f082063",
            "port": "061aa997-2f30-4591-8841-fb6abf5c3b2e"
          },
          "target": {
            "block": "100ebdff-c571-4fd5-b8f8-7b497486687c",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "e4af3711-fee4-49f3-b959-5d00a8bdc9b6",
            "port": "061aa997-2f30-4591-8841-fb6abf5c3b2e"
          },
          "target": {
            "block": "20ba284a-6a58-4db2-a224-e7be5f74717f",
            "port": "in"
          }
        }
      ]
    }
  },
  "dependencies": {
    "2d00dc6cbf770622c583a0dff0e0d8e2763ab2ec": {
      "package": {
        "name": "Mux 2:1",
        "version": "1.0.0",
        "description": "Multiplexer 2:1",
        "author": "Carlos Diaz",
        "image": "%3Csvg%20xmlns=%22http://www.w3.org/2000/svg%22%20viewBox=%22-252%20400.9%2090%2040%22%3E%3Cpath%20d=%22M-162%20419.9h-24v-7.2l-41-11.8v9h-25v2h25v18h-25v2h25v9l41-11.7v-7.4h24v-1.9zm-63%2018.5v-35l37%2010.8v13.5l-37%2010.7z%22/%3E%3C/svg%3E"
      },
      "design": {
        "graph": {
          "blocks": [
            {
              "id": "c3f73f68-1074-4355-b69f-6a20f7bea3e7",
              "type": "basic.input",
              "data": {
                "name": "i0"
              },
              "position": {
                "x": 80,
                "y": 120
              }
            },
            {
              "id": "5fb29465-2ee7-45bb-afa4-9a3de895c774",
              "type": "basic.input",
              "data": {
                "name": "i1"
              },
              "position": {
                "x": 80,
                "y": 208
              }
            },
            {
              "id": "061aa997-2f30-4591-8841-fb6abf5c3b2e",
              "type": "basic.output",
              "data": {
                "name": "o"
              },
              "position": {
                "x": 792,
                "y": 208
              }
            },
            {
              "id": "67ed5e09-486d-4f97-929f-aefea9c43951",
              "type": "basic.input",
              "data": {
                "name": "sel"
              },
              "position": {
                "x": 80,
                "y": 296
              }
            },
            {
              "id": "ba573190-2ead-411a-a323-1b15a22d46db",
              "type": "basic.code",
              "data": {
                "code": "reg _o;\n\nalways @(*) begin\n    case(sel0)\n        0: _o = in0;\n        1: _o = in1;\n        default: _o = in0;\n    endcase\nend\n\nassign o = _o;",
                "params": [],
                "ports": {
                  "in": [
                    {
                      "name": "in0"
                    },
                    {
                      "name": "in1"
                    },
                    {
                      "name": "sel0"
                    }
                  ],
                  "out": [
                    {
                      "name": "o"
                    }
                  ]
                }
              },
              "position": {
                "x": 312,
                "y": 112
              },
              "size": {
                "width": 384,
                "height": 256
              }
            }
          ],
          "wires": [
            {
              "source": {
                "block": "ba573190-2ead-411a-a323-1b15a22d46db",
                "port": "o"
              },
              "target": {
                "block": "061aa997-2f30-4591-8841-fb6abf5c3b2e",
                "port": "in"
              }
            },
            {
              "source": {
                "block": "c3f73f68-1074-4355-b69f-6a20f7bea3e7",
                "port": "out"
              },
              "target": {
                "block": "ba573190-2ead-411a-a323-1b15a22d46db",
                "port": "in0"
              }
            },
            {
              "source": {
                "block": "5fb29465-2ee7-45bb-afa4-9a3de895c774",
                "port": "out"
              },
              "target": {
                "block": "ba573190-2ead-411a-a323-1b15a22d46db",
                "port": "in1"
              }
            },
            {
              "source": {
                "block": "67ed5e09-486d-4f97-929f-aefea9c43951",
                "port": "out"
              },
              "target": {
                "block": "ba573190-2ead-411a-a323-1b15a22d46db",
                "port": "sel0"
              }
            }
          ]
        }
      }
    }
  }
}