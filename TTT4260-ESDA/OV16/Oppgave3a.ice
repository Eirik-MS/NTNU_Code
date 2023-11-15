{
  "version": "1.2",
  "package": {
    "name": "",
    "version": "",
    "description": "",
    "author": "",
    "image": ""
  },
  "design": {
    "board": "go-board",
    "graph": {
      "blocks": [
        {
          "id": "c66af963-cf77-4c96-bfaf-19593d2744ac",
          "type": "basic.input",
          "data": {
            "name": "Button",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "SW1",
                "value": "53"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 472,
            "y": 528
          }
        },
        {
          "id": "ed40fbc6-4465-4ed3-b948-c1639a068f43",
          "type": "basic.output",
          "data": {
            "name": "Led1",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "LED1",
                "value": "56"
              }
            ]
          },
          "position": {
            "x": 800,
            "y": 568
          }
        },
        {
          "id": "53b41207-c220-4542-abe2-58aa4b74b24b",
          "type": "basic.output",
          "data": {
            "name": "Led2",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "LED2",
                "value": "57"
              }
            ]
          },
          "position": {
            "x": 936,
            "y": 568
          }
        },
        {
          "id": "ef5f156d-6c1d-4ba2-bc7b-8663c19e4fd2",
          "type": "basic.output",
          "data": {
            "name": "Led3",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "LED3",
                "value": "59"
              }
            ]
          },
          "position": {
            "x": 1080,
            "y": 568
          }
        },
        {
          "id": "7322e781-2563-4001-a500-cf47d0f57cda",
          "type": "basic.output",
          "data": {
            "name": "Led4",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "LED4",
                "value": "60"
              }
            ]
          },
          "position": {
            "x": 1224,
            "y": 568
          }
        },
        {
          "id": "45c23d71-8cd9-4a87-8122-f1fce3414ff4",
          "type": "basic.constant",
          "data": {
            "name": "Prescaler",
            "value": "25",
            "local": false
          },
          "position": {
            "x": 472,
            "y": 296
          }
        },
        {
          "id": "eaaeb8a5-d09b-43d7-81b6-cfbdbc30c9dc",
          "type": "6a50747141af6d1cfb3bb9d0093fb94862ff5a65",
          "position": {
            "x": 472,
            "y": 440
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "5b8d21b4-158b-4a47-9164-ce42c5653673",
          "type": "8b89a54940796d87a750d07e9b511ed41621037e",
          "position": {
            "x": 656,
            "y": 456
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "e43042ed-cdea-4ff7-b98a-267bf92aa793",
          "type": "8b89a54940796d87a750d07e9b511ed41621037e",
          "position": {
            "x": 800,
            "y": 432
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "745a277b-792e-4a9f-b6de-9cbac197ab0e",
          "type": "8b89a54940796d87a750d07e9b511ed41621037e",
          "position": {
            "x": 952,
            "y": 408
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "a66b7126-72ea-4914-a3e6-98198150b3a6",
          "type": "8b89a54940796d87a750d07e9b511ed41621037e",
          "position": {
            "x": 1088,
            "y": 352
          },
          "size": {
            "width": 96,
            "height": 64
          }
        }
      ],
      "wires": [
        {
          "source": {
            "block": "45c23d71-8cd9-4a87-8122-f1fce3414ff4",
            "port": "constant-out"
          },
          "target": {
            "block": "eaaeb8a5-d09b-43d7-81b6-cfbdbc30c9dc",
            "port": "de2d8a2d-7908-48a2-9e35-7763a45886e4"
          }
        },
        {
          "source": {
            "block": "eaaeb8a5-d09b-43d7-81b6-cfbdbc30c9dc",
            "port": "7e07d449-6475-4839-b43e-8aead8be2aac"
          },
          "target": {
            "block": "5b8d21b4-158b-4a47-9164-ce42c5653673",
            "port": "6855f64f-fa1c-4371-b2e1-a98970674a96"
          }
        },
        {
          "source": {
            "block": "eaaeb8a5-d09b-43d7-81b6-cfbdbc30c9dc",
            "port": "7e07d449-6475-4839-b43e-8aead8be2aac"
          },
          "target": {
            "block": "e43042ed-cdea-4ff7-b98a-267bf92aa793",
            "port": "6855f64f-fa1c-4371-b2e1-a98970674a96"
          }
        },
        {
          "source": {
            "block": "eaaeb8a5-d09b-43d7-81b6-cfbdbc30c9dc",
            "port": "7e07d449-6475-4839-b43e-8aead8be2aac"
          },
          "target": {
            "block": "745a277b-792e-4a9f-b6de-9cbac197ab0e",
            "port": "6855f64f-fa1c-4371-b2e1-a98970674a96"
          }
        },
        {
          "source": {
            "block": "eaaeb8a5-d09b-43d7-81b6-cfbdbc30c9dc",
            "port": "7e07d449-6475-4839-b43e-8aead8be2aac"
          },
          "target": {
            "block": "a66b7126-72ea-4914-a3e6-98198150b3a6",
            "port": "6855f64f-fa1c-4371-b2e1-a98970674a96"
          }
        },
        {
          "source": {
            "block": "a66b7126-72ea-4914-a3e6-98198150b3a6",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "7322e781-2563-4001-a500-cf47d0f57cda",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "745a277b-792e-4a9f-b6de-9cbac197ab0e",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "ef5f156d-6c1d-4ba2-bc7b-8663c19e4fd2",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "e43042ed-cdea-4ff7-b98a-267bf92aa793",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "53b41207-c220-4542-abe2-58aa4b74b24b",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "5b8d21b4-158b-4a47-9164-ce42c5653673",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "ed40fbc6-4465-4ed3-b948-c1639a068f43",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "c66af963-cf77-4c96-bfaf-19593d2744ac",
            "port": "out"
          },
          "target": {
            "block": "5b8d21b4-158b-4a47-9164-ce42c5653673",
            "port": "b32a6101-5bd1-4bcf-ae5f-e569b958a6a2"
          }
        },
        {
          "source": {
            "block": "5b8d21b4-158b-4a47-9164-ce42c5653673",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "e43042ed-cdea-4ff7-b98a-267bf92aa793",
            "port": "b32a6101-5bd1-4bcf-ae5f-e569b958a6a2"
          }
        },
        {
          "source": {
            "block": "e43042ed-cdea-4ff7-b98a-267bf92aa793",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "745a277b-792e-4a9f-b6de-9cbac197ab0e",
            "port": "b32a6101-5bd1-4bcf-ae5f-e569b958a6a2"
          }
        },
        {
          "source": {
            "block": "745a277b-792e-4a9f-b6de-9cbac197ab0e",
            "port": "ffdd9aa2-aea3-4aa9-8431-80e799226774"
          },
          "target": {
            "block": "a66b7126-72ea-4914-a3e6-98198150b3a6",
            "port": "b32a6101-5bd1-4bcf-ae5f-e569b958a6a2"
          }
        }
      ]
    }
  },
  "dependencies": {
    "6a50747141af6d1cfb3bb9d0093fb94862ff5a65": {
      "package": {
        "name": "PrescalerN",
        "version": "0.1",
        "description": "Parametric N-bits prescaler",
        "author": "Juan Gonzalez (Obijuan)",
        "image": ""
      },
      "design": {
        "graph": {
          "blocks": [
            {
              "id": "e19c6f2f-5747-4ed1-87c8-748575f0cc10",
              "type": "basic.input",
              "data": {
                "name": "",
                "clock": true
              },
              "position": {
                "x": 0,
                "y": 256
              }
            },
            {
              "id": "7e07d449-6475-4839-b43e-8aead8be2aac",
              "type": "basic.output",
              "data": {
                "name": ""
              },
              "position": {
                "x": 720,
                "y": 256
              }
            },
            {
              "id": "de2d8a2d-7908-48a2-9e35-7763a45886e4",
              "type": "basic.constant",
              "data": {
                "name": "N",
                "value": "22",
                "local": false
              },
              "position": {
                "x": 352,
                "y": 56
              }
            },
            {
              "id": "2330955f-5ce6-4d1c-8ee4-0a09a0349389",
              "type": "basic.code",
              "data": {
                "code": "//-- Number of bits of the prescaler\n//parameter N = 22;\n\n//-- divisor register\nreg [N-1:0] divcounter;\n\n//-- N bit counter\nalways @(posedge clk_in)\n  divcounter <= divcounter + 1;\n\n//-- Use the most significant bit as output\nassign clk_out = divcounter[N-1];",
                "params": [
                  {
                    "name": "N"
                  }
                ],
                "ports": {
                  "in": [
                    {
                      "name": "clk_in"
                    }
                  ],
                  "out": [
                    {
                      "name": "clk_out"
                    }
                  ]
                }
              },
              "position": {
                "x": 176,
                "y": 176
              },
              "size": {
                "width": 448,
                "height": 224
              }
            }
          ],
          "wires": [
            {
              "source": {
                "block": "2330955f-5ce6-4d1c-8ee4-0a09a0349389",
                "port": "clk_out"
              },
              "target": {
                "block": "7e07d449-6475-4839-b43e-8aead8be2aac",
                "port": "in"
              }
            },
            {
              "source": {
                "block": "e19c6f2f-5747-4ed1-87c8-748575f0cc10",
                "port": "out"
              },
              "target": {
                "block": "2330955f-5ce6-4d1c-8ee4-0a09a0349389",
                "port": "clk_in"
              }
            },
            {
              "source": {
                "block": "de2d8a2d-7908-48a2-9e35-7763a45886e4",
                "port": "constant-out"
              },
              "target": {
                "block": "2330955f-5ce6-4d1c-8ee4-0a09a0349389",
                "port": "N"
              }
            }
          ]
        }
      }
    },
    "8b89a54940796d87a750d07e9b511ed41621037e": {
      "package": {
        "name": "Flip-flop D",
        "version": "1.0.0",
        "description": "Delay flip-flop",
        "author": "Carlos Diaz",
        "image": "%3Csvg%20xmlns=%22http://www.w3.org/2000/svg%22%20viewBox=%22-252%20400.9%2090%2040%22%3E%3Ctext%20style=%22line-height:125%25%22%20x=%22-231.121%22%20y=%22429.867%22%20font-weight=%22400%22%20font-size=%2224.601%22%20font-family=%22sans-serif%22%20letter-spacing=%220%22%20word-spacing=%220%22%3E%3Ctspan%20x=%22-231.121%22%20y=%22429.867%22%3EDFF%3C/tspan%3E%3C/text%3E%3C/svg%3E"
      },
      "design": {
        "graph": {
          "blocks": [
            {
              "id": "6855f64f-fa1c-4371-b2e1-a98970674a96",
              "type": "basic.input",
              "data": {
                "name": "",
                "clock": true
              },
              "position": {
                "x": 232,
                "y": 168
              }
            },
            {
              "id": "ffdd9aa2-aea3-4aa9-8431-80e799226774",
              "type": "basic.output",
              "data": {
                "name": ""
              },
              "position": {
                "x": 864,
                "y": 232
              }
            },
            {
              "id": "b32a6101-5bd1-4bcf-ae5f-e569b958a6a2",
              "type": "basic.input",
              "data": {
                "name": "",
                "clock": false
              },
              "position": {
                "x": 232,
                "y": 304
              }
            },
            {
              "id": "e5222a6e-4717-4f08-99d7-7cde897060ca",
              "type": "basic.code",
              "data": {
                "code": "// D flip-flop\n\nreg q = 1'b0;\n\nalways @(posedge clk)\nbegin\n  q <= d;\nend\n\n",
                "params": [],
                "ports": {
                  "in": [
                    {
                      "name": "clk"
                    },
                    {
                      "name": "d"
                    }
                  ],
                  "out": [
                    {
                      "name": "q"
                    }
                  ]
                }
              },
              "position": {
                "x": 432,
                "y": 128
              },
              "size": {
                "width": 368,
                "height": 272
              }
            }
          ],
          "wires": [
            {
              "source": {
                "block": "b32a6101-5bd1-4bcf-ae5f-e569b958a6a2",
                "port": "out"
              },
              "target": {
                "block": "e5222a6e-4717-4f08-99d7-7cde897060ca",
                "port": "d"
              }
            },
            {
              "source": {
                "block": "6855f64f-fa1c-4371-b2e1-a98970674a96",
                "port": "out"
              },
              "target": {
                "block": "e5222a6e-4717-4f08-99d7-7cde897060ca",
                "port": "clk"
              }
            },
            {
              "source": {
                "block": "e5222a6e-4717-4f08-99d7-7cde897060ca",
                "port": "q"
              },
              "target": {
                "block": "ffdd9aa2-aea3-4aa9-8431-80e799226774",
                "port": "in"
              }
            }
          ]
        }
      }
    }
  }
}