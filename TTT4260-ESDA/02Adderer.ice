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
          "id": "1ddf574b-0411-4f5a-a3e6-0f723e20dd34",
          "type": "basic.input",
          "data": {
            "name": "A",
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
            "x": 184,
            "y": 464
          }
        },
        {
          "id": "9d0228bf-ad71-458d-9cab-1abc26fe3c89",
          "type": "basic.output",
          "data": {
            "name": "Sum",
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
            "x": 920,
            "y": 544
          }
        },
        {
          "id": "1ecd7491-6f34-467a-b703-9854b9d0a36f",
          "type": "basic.input",
          "data": {
            "name": "B",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "SW2",
                "value": "51"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 184,
            "y": 600
          }
        },
        {
          "id": "ef1b53f4-3bf2-43b2-a7fe-0057500a12c3",
          "type": "basic.input",
          "data": {
            "name": "Ci",
            "virtual": false,
            "pins": [
              {
                "index": "0",
                "name": "SW3",
                "value": "54"
              }
            ],
            "clock": false
          },
          "position": {
            "x": 480,
            "y": 600
          }
        },
        {
          "id": "cb4afa81-e1af-4d67-ad50-950bd9423cef",
          "type": "basic.output",
          "data": {
            "name": "Carry",
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
            "x": 984,
            "y": 704
          }
        },
        {
          "id": "5ca1bf8b-d1d0-4131-b3ff-df479e807bbe",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 448,
            "y": 496
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "f6110146-af82-450f-ae5d-64660f8f4438",
          "type": "e9ceb27ad69f0785afc607dcd7f0924f517182e9",
          "position": {
            "x": 760,
            "y": 544
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "addb1857-88d1-46ee-8535-79c090cf4b24",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 664,
            "y": 640
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "27b97a81-46e2-487f-8f0e-72deaf92e12f",
          "type": "7ebc902cbb1c4db116741533a86182485900ecda",
          "position": {
            "x": 544,
            "y": 744
          },
          "size": {
            "width": 96,
            "height": 64
          }
        },
        {
          "id": "e880ca03-dd42-4fa5-bf5d-6cb98ecfa289",
          "type": "528969443d4d498610fee60503f6bdebb087af5e",
          "position": {
            "x": 848,
            "y": 704
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
            "block": "1ddf574b-0411-4f5a-a3e6-0f723e20dd34",
            "port": "out"
          },
          "target": {
            "block": "5ca1bf8b-d1d0-4131-b3ff-df479e807bbe",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "1ecd7491-6f34-467a-b703-9854b9d0a36f",
            "port": "out"
          },
          "target": {
            "block": "5ca1bf8b-d1d0-4131-b3ff-df479e807bbe",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "1ecd7491-6f34-467a-b703-9854b9d0a36f",
            "port": "out"
          },
          "target": {
            "block": "27b97a81-46e2-487f-8f0e-72deaf92e12f",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 320,
              "y": 712
            }
          ]
        },
        {
          "source": {
            "block": "1ddf574b-0411-4f5a-a3e6-0f723e20dd34",
            "port": "out"
          },
          "target": {
            "block": "27b97a81-46e2-487f-8f0e-72deaf92e12f",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          },
          "vertices": [
            {
              "x": 368,
              "y": 696
            }
          ]
        },
        {
          "source": {
            "block": "5ca1bf8b-d1d0-4131-b3ff-df479e807bbe",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "f6110146-af82-450f-ae5d-64660f8f4438",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          },
          "vertices": [
            {
              "x": 584,
              "y": 528
            }
          ]
        },
        {
          "source": {
            "block": "ef1b53f4-3bf2-43b2-a7fe-0057500a12c3",
            "port": "out"
          },
          "target": {
            "block": "f6110146-af82-450f-ae5d-64660f8f4438",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "ef1b53f4-3bf2-43b2-a7fe-0057500a12c3",
            "port": "out"
          },
          "target": {
            "block": "addb1857-88d1-46ee-8535-79c090cf4b24",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "5ca1bf8b-d1d0-4131-b3ff-df479e807bbe",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "addb1857-88d1-46ee-8535-79c090cf4b24",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          },
          "vertices": [
            {
              "x": 608,
              "y": 584
            }
          ]
        },
        {
          "source": {
            "block": "27b97a81-46e2-487f-8f0e-72deaf92e12f",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "e880ca03-dd42-4fa5-bf5d-6cb98ecfa289",
            "port": "97b51945-d716-4b6c-9db9-970d08541249"
          }
        },
        {
          "source": {
            "block": "addb1857-88d1-46ee-8535-79c090cf4b24",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "e880ca03-dd42-4fa5-bf5d-6cb98ecfa289",
            "port": "18c2ebc7-5152-439c-9b3f-851c59bac834"
          }
        },
        {
          "source": {
            "block": "e880ca03-dd42-4fa5-bf5d-6cb98ecfa289",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "cb4afa81-e1af-4d67-ad50-950bd9423cef",
            "port": "in"
          }
        },
        {
          "source": {
            "block": "f6110146-af82-450f-ae5d-64660f8f4438",
            "port": "664caf9e-5f40-4df4-800a-b626af702e62"
          },
          "target": {
            "block": "9d0228bf-ad71-458d-9cab-1abc26fe3c89",
            "port": "in"
          }
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