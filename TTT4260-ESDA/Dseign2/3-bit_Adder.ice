{
  "version": "1.2",
  "package": {
    "name": "3-bit Adder",
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
          "id": "be8a5288-69e9-40f6-ad58-8f64c21826c1",
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
            "x": 240,
            "y": -72
          }
        },
        {
          "id": "fe80c4b0-7c1b-440e-b5b3-1963af681341",
          "type": "basic.output",
          "data": {
            "name": "Q1",
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
            "x": 672,
            "y": -56
          }
        },
        {
          "id": "d67b1dd9-6c01-4dc8-b4b8-472c10379c0b",
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
            "x": 240,
            "y": 32
          }
        },
        {
          "id": "306acddf-dec7-4a1e-bc48-d4d48e2f8995",
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
            "x": 240,
            "y": 136
          }
        },
        {
          "id": "c97735f3-bba4-4fa2-9354-bb1c422a33c7",
          "type": "basic.output",
          "data": {
            "name": "Q2",
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
            "x": 928,
            "y": 136
          }
        },
        {
          "id": "254aa21c-2c68-40ee-abe1-c8535e89bedb",
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
            "x": 240,
            "y": 272
          }
        },
        {
          "id": "5a55b284-13e6-4179-bc26-d79f3f6c4793",
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
            "x": 240,
            "y": 408
          }
        },
        {
          "id": "30f707a9-1593-4233-a430-67c1066e2832",
          "type": "basic.output",
          "data": {
            "name": "Q3",
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
            "x": 1296,
            "y": 416
          }
        },
        {
          "id": "88e5061e-a06d-45fd-bede-56f9cb8c3310",
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
            "x": 240,
            "y": 536
          }
        },
        {
          "id": "ffa48552-8a40-4ab3-a6c4-a64b65e1b37f",
          "type": "basic.output",
          "data": {
            "name": "C_out",
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
            "x": 1392,
            "y": 600
          }
        },
        {
          "id": "d126dc6c-096f-4a6f-ab23-202836a44c5c",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 440,
            "y": -56
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "45529be8-5202-4ba8-9dd3-93e5eebae3a8",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 520,
            "y": 152
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "b007cab1-f930-4081-8665-c72a4d94cc97",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 720,
            "y": 136
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "a124800b-f49f-4015-86af-23f09c02371d",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 488,
            "y": 48
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "871de064-bf52-4f4c-9620-7388ef355713",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 680,
            "y": 240
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "97c99d6a-8d86-4fbe-8537-b00e9e7f3e92",
          "type": "528969443d4d498610fee60503f6bdebb087af5e",
          "position": {
            "x": 832,
            "y": 280
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "3eaf84c4-e663-4b5e-bab4-b28a40d13e93",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 488,
            "y": 264
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "6c38baff-924f-4e75-8ec0-6493fd70050a",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 920,
            "y": 432
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "1832d607-ddec-4af5-839c-573e719d0acc",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 1120,
            "y": 416
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "42553885-01ea-494a-a55c-e6e13f5ade26",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 984,
            "y": 616
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "463a4990-7d26-45fb-9608-d99207344ac7",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 1080,
            "y": 528
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "9de3fb2c-1a9f-4829-8549-8faebcb07223",
          "type": "528969443d4d498610fee60503f6bdebb087af5e",
          "position": {
            "x": 1248,
            "y": 600
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
            "block": "be8a5288-69e9-40f6-ad58-8f64c21826c1",
            "port": "out"
          },
          "target": {
            "block": "d126dc6c-096f-4a6f-ab23-202836a44c5c",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "45529be8-5202-4ba8-9dd3-93e5eebae3a8",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "b007cab1-f930-4081-8665-c72a4d94cc97",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "a124800b-f49f-4015-86af-23f09c02371d",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "b007cab1-f930-4081-8665-c72a4d94cc97",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "45529be8-5202-4ba8-9dd3-93e5eebae3a8",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "871de064-bf52-4f4c-9620-7388ef355713",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 632,
              "y": 216
            }
          ]
        },
        {
          "source": {
            "block": "a124800b-f49f-4015-86af-23f09c02371d",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "871de064-bf52-4f4c-9620-7388ef355713",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "871de064-bf52-4f4c-9620-7388ef355713",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "97c99d6a-8d86-4fbe-8537-b00e9e7f3e92",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "3eaf84c4-e663-4b5e-bab4-b28a40d13e93",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "97c99d6a-8d86-4fbe-8537-b00e9e7f3e92",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 600,
              "y": 312
            }
          ]
        },
        {
          "source": {
            "block": "97c99d6a-8d86-4fbe-8537-b00e9e7f3e92",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "1832d607-ddec-4af5-839c-573e719d0acc",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "6c38baff-924f-4e75-8ec0-6493fd70050a",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "1832d607-ddec-4af5-839c-573e719d0acc",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "6c38baff-924f-4e75-8ec0-6493fd70050a",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "463a4990-7d26-45fb-9608-d99207344ac7",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "97c99d6a-8d86-4fbe-8537-b00e9e7f3e92",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "463a4990-7d26-45fb-9608-d99207344ac7",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 1040,
              "y": 400
            }
          ]
        },
        {
          "source": {
            "block": "42553885-01ea-494a-a55c-e6e13f5ade26",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "9de3fb2c-1a9f-4829-8549-8faebcb07223",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "463a4990-7d26-45fb-9608-d99207344ac7",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "9de3fb2c-1a9f-4829-8549-8faebcb07223",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "d126dc6c-096f-4a6f-ab23-202836a44c5c",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "fe80c4b0-7c1b-440e-b5b3-1963af681341",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "b007cab1-f930-4081-8665-c72a4d94cc97",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "c97735f3-bba4-4fa2-9354-bb1c422a33c7",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "1832d607-ddec-4af5-839c-573e719d0acc",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "30f707a9-1593-4233-a430-67c1066e2832",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "9de3fb2c-1a9f-4829-8549-8faebcb07223",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "ffa48552-8a40-4ab3-a6c4-a64b65e1b37f",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "be8a5288-69e9-40f6-ad58-8f64c21826c1",
            "port": "out"
          },
          "target": {
            "block": "a124800b-f49f-4015-86af-23f09c02371d",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "d67b1dd9-6c01-4dc8-b4b8-472c10379c0b",
            "port": "out"
          },
          "target": {
            "block": "45529be8-5202-4ba8-9dd3-93e5eebae3a8",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          },
          "vertices": [
            {
              "x": 392,
              "y": 136
            }
          ]
        },
        {
          "source": {
            "block": "5a55b284-13e6-4179-bc26-d79f3f6c4793",
            "port": "out"
          },
          "target": {
            "block": "45529be8-5202-4ba8-9dd3-93e5eebae3a8",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 456,
              "y": 344
            }
          ]
        },
        {
          "source": {
            "block": "5a55b284-13e6-4179-bc26-d79f3f6c4793",
            "port": "out"
          },
          "target": {
            "block": "3eaf84c4-e663-4b5e-bab4-b28a40d13e93",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 456,
              "y": 368
            }
          ]
        },
        {
          "source": {
            "block": "d67b1dd9-6c01-4dc8-b4b8-472c10379c0b",
            "port": "out"
          },
          "target": {
            "block": "3eaf84c4-e663-4b5e-bab4-b28a40d13e93",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          },
          "vertices": [
            {
              "x": 392,
              "y": 128
            }
          ]
        },
        {
          "source": {
            "block": "254aa21c-2c68-40ee-abe1-c8535e89bedb",
            "port": "out"
          },
          "target": {
            "block": "d126dc6c-096f-4a6f-ab23-202836a44c5c",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 416,
              "y": 136
            }
          ]
        },
        {
          "source": {
            "block": "254aa21c-2c68-40ee-abe1-c8535e89bedb",
            "port": "out"
          },
          "target": {
            "block": "a124800b-f49f-4015-86af-23f09c02371d",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 416,
              "y": 160
            }
          ]
        },
        {
          "source": {
            "block": "306acddf-dec7-4a1e-bc48-d4d48e2f8995",
            "port": "out"
          },
          "target": {
            "block": "6c38baff-924f-4e75-8ec0-6493fd70050a",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          },
          "vertices": [
            {
              "x": 368,
              "y": 392
            }
          ]
        },
        {
          "source": {
            "block": "88e5061e-a06d-45fd-bede-56f9cb8c3310",
            "port": "out"
          },
          "target": {
            "block": "6c38baff-924f-4e75-8ec0-6493fd70050a",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "88e5061e-a06d-45fd-bede-56f9cb8c3310",
            "port": "out"
          },
          "target": {
            "block": "42553885-01ea-494a-a55c-e6e13f5ade26",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "306acddf-dec7-4a1e-bc48-d4d48e2f8995",
            "port": "out"
          },
          "target": {
            "block": "42553885-01ea-494a-a55c-e6e13f5ade26",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 368,
              "y": 496
            }
          ]
        }
      ]
    }
  },
  "dependencies": {
    "e9ceb27ad69f0785afc607dcd7f0924f517182e9": {
      "package": {
        "name": "XOR",
        "version": "1.0.0",
        "description": "XOR logic gate",
        "author": "Carlos Diaz",
        "image": "%3Csvg%20xmlns=%22http://www.w3.org/2000/svg%22%20viewBox=%22-252%20400.9%2090%2040%22%3E%3Cpath%20d=%22M-252%20409.9h26v2h-26zM-252%20429.9h27v2h-27zM-186.5%20419.9h24.5v2h-24.5z%22/%3E%3Cpath%20d=%22M-184.6%20420.9c0-1-.6-2-.6-2-10.3-17.8-26-18-30.6-18H-233l2%202.4s5.7%207%205.7%2017.6c0%2010.6-5.7%2017.6-5.7%2017.6l-2%202.4h17.2c2.4%200%207.7%200%2013.6-2.4%205.7-2.3%2012-6.9%2017-15.7.1%200%20.6-1%20.6-1.9zm-18.9%2014.8c-5.4%202.2-9.8%202.2-12.3%202.2H-227c1.9-3.1%204.8-9%204.8-17s-2.9-13.9-4.8-17h11.3c4.7%200%2018.3-.1%2028%2017-4.8%208.4-10.6%2012.7-15.8%2014.8z%22/%3E%3Cpath%20d=%22M-238.3%20440.9h3.6c2.3-3.7%206.5-11.6%206.5-19.8%200-8.5-4.4-16.5-6.8-20.2h-3.6c1.4%202%207.4%2011%207.4%2020.2%200%208.9-5.7%2017.7-7.1%2019.8z%22/%3E%3C/svg%3E"
      },
      "design": {
        "graph": {
          "blocks": [
            {
              "id": "18c2ebc7-5152-439c-9b3f-851c59bac834",
              "type": "basic.input",
              "data": {
                "name": ""
              },
              "position": {
                "x": 64,
                "y": 80
              }
            },
            {
              "id": "664caf9e-5f40-4df4-800a-b626af702e62",
              "type": "basic.output",
              "data": {
                "name": ""
              },
              "position": {
                "x": 752,
                "y": 144
              }
            },
            {
              "id": "97b51945-d716-4b6c-9db9-970d08541249",
              "type": "basic.input",
              "data": {
                "name": ""
              },
              "position": {
                "x": 64,
                "y": 208
              }
            },
            {
              "id": "00925b04-5004-4307-a737-fa4e97c8b6ab",
              "type": "basic.code",
              "data": {
                "code": "// XOR logic gate\n\nassign c = a ^ b;",
                "params": [],
                "ports": {
                  "in": [
                    {
                      "name": "a"
                    },
                    {
                      "name": "b"
                    }
                  ],
                  "out": [
                    {
                      "name": "c"
                    }
                  ]
                }
              },
              "position": {
                "x": 256,
                "y": 48
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
                "block": "18c2ebc7-5152-439c-9b3f-851c59bac834",
                "port": "out"
              },
              "target": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "a"
              }
            },
            {
              "source": {
                "block": "97b51945-d716-4b6c-9db9-970d08541249",
                "port": "out"
              },
              "target": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "b"
              }
            },
            {
              "source": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "c"
              },
              "target": {
                "block": "664caf9e-5f40-4df4-800a-b626af702e62",
                "port": "in"
              }
            }
          ]
        }
      }
    },
    "7ebc902cbb1c4db116741533a86182485900ecda": {
      "package": {
        "name": "AND",
        "version": "1.0.0",
        "description": "AND logic gate",
        "author": "Jesús Arroyo",
        "image": "%3Csvg%20xmlns=%22http://www.w3.org/2000/svg%22%20viewBox=%22-252%20400.9%2090%2040%22%3E%3Cpath%20d=%22M-252%20409.9h26v2h-26zM-252%20429.9h27v2h-27z%22/%3E%3Cpath%20d=%22M-227%20400.9v39.9h20.4c11.3%200%2020-9%2020-20s-8.7-20-20-20H-227zm2.9%202.8h17.6c9.8%200%2016.7%207.6%2016.7%2017.1%200%209.5-7.4%2017.1-17.1%2017.1H-224c-.1.1-.1-34.2-.1-34.2z%22/%3E%3Cpath%20d=%22M-187.911%20419.9H-162v2h-25.911z%22/%3E%3C/svg%3E"
      },
      "design": {
        "graph": {
          "blocks": [
            {
              "id": "18c2ebc7-5152-439c-9b3f-851c59bac834",
              "type": "basic.input",
              "data": {
                "name": ""
              },
              "position": {
                "x": 64,
                "y": 80
              }
            },
            {
              "id": "664caf9e-5f40-4df4-800a-b626af702e62",
              "type": "basic.output",
              "data": {
                "name": ""
              },
              "position": {
                "x": 752,
                "y": 144
              }
            },
            {
              "id": "97b51945-d716-4b6c-9db9-970d08541249",
              "type": "basic.input",
              "data": {
                "name": ""
              },
              "position": {
                "x": 64,
                "y": 208
              }
            },
            {
              "id": "00925b04-5004-4307-a737-fa4e97c8b6ab",
              "type": "basic.code",
              "data": {
                "code": "// AND logic gate\n\nassign c = a & b;",
                "params": [],
                "ports": {
                  "in": [
                    {
                      "name": "a"
                    },
                    {
                      "name": "b"
                    }
                  ],
                  "out": [
                    {
                      "name": "c"
                    }
                  ]
                }
              },
              "position": {
                "x": 256,
                "y": 48
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
                "block": "18c2ebc7-5152-439c-9b3f-851c59bac834",
                "port": "out"
              },
              "target": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "a"
              }
            },
            {
              "source": {
                "block": "97b51945-d716-4b6c-9db9-970d08541249",
                "port": "out"
              },
              "target": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "b"
              }
            },
            {
              "source": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "c"
              },
              "target": {
                "block": "664caf9e-5f40-4df4-800a-b626af702e62",
                "port": "in"
              }
            }
          ]
        }
      }
    },
    "528969443d4d498610fee60503f6bdebb087af5e": {
      "package": {
        "name": "OR",
        "version": "1.0.0",
        "description": "OR logic gate",
        "author": "Jesús Arroyo",
        "image": "%3Csvg%20xmlns=%22http://www.w3.org/2000/svg%22%20width=%2290%22%20height=%2240%22%20version=%221%22%3E%3Cpath%20d=%22M65%2020h25M26%2010H0M27%2030H0%22%20fill=%22none%22%20stroke=%22#000%22%20stroke-width=%222%22/%3E%3Cpath%20d=%22M19.094%200l2%202.438s5.656%207%205.656%2017.562c0%2010.562-5.656%2017.563-5.656%2017.563l-2%202.437H36.25c2.408%200%207.69.025%2013.625-2.406s12.537-7.344%2017.688-16.875L66.25%2020l1.313-.719C57.258.216%2041.007%200%2036.25%200H19.094zm5.875%203H36.25c4.684%200%2018.287-.13%2027.969%2017-4.767%208.43-10.522%2012.684-15.719%2014.813C43.14%2037.008%2038.658%2037%2036.25%2037H25c1.874-3.108%204.75-9.05%204.75-17%200-7.973-2.909-13.9-4.781-17z%22%20fill-rule=%22evenodd%22/%3E%3C/svg%3E"
      },
      "design": {
        "graph": {
          "blocks": [
            {
              "id": "18c2ebc7-5152-439c-9b3f-851c59bac834",
              "type": "basic.input",
              "data": {
                "name": ""
              },
              "position": {
                "x": 64,
                "y": 80
              }
            },
            {
              "id": "664caf9e-5f40-4df4-800a-b626af702e62",
              "type": "basic.output",
              "data": {
                "name": ""
              },
              "position": {
                "x": 752,
                "y": 144
              }
            },
            {
              "id": "97b51945-d716-4b6c-9db9-970d08541249",
              "type": "basic.input",
              "data": {
                "name": ""
              },
              "position": {
                "x": 64,
                "y": 208
              }
            },
            {
              "id": "00925b04-5004-4307-a737-fa4e97c8b6ab",
              "type": "basic.code",
              "data": {
                "code": "// OR logic gate\n\nassign c = a | b;",
                "params": [],
                "ports": {
                  "in": [
                    {
                      "name": "a"
                    },
                    {
                      "name": "b"
                    }
                  ],
                  "out": [
                    {
                      "name": "c"
                    }
                  ]
                }
              },
              "position": {
                "x": 256,
                "y": 48
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
                "block": "18c2ebc7-5152-439c-9b3f-851c59bac834",
                "port": "out"
              },
              "target": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "a"
              }
            },
            {
              "source": {
                "block": "97b51945-d716-4b6c-9db9-970d08541249",
                "port": "out"
              },
              "target": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "b"
              }
            },
            {
              "source": {
                "block": "00925b04-5004-4307-a737-fa4e97c8b6ab",
                "port": "c"
              },
              "target": {
                "block": "664caf9e-5f40-4df4-800a-b626af702e62",
                "port": "in"
              }
            }
          ]
        }
      }
    }
  }
}