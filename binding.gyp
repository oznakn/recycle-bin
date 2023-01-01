{
  "targets": [
    {
      "target_name": "trash",
      "sources": [
        "src/export.cc",
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": [
        "NAPI_CPP_EXCEPTIONS",
        "NAPI_VERSION=3",
      ],
      "conditions": [
        [
          'OS=="mac"',
          {
            "sources": [
              "src/trash_darwin.mm"
            ],
            "link_settings": {
              "libraries": [
                "-framework Cocoa",
                "-framework CoreFoundation",
              ]
            },
            "xcode_settings": {
              "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
              "CLANG_ENABLE_OBJC_ARC": "YES",
              "OTHER_CFLAGS": [
                "-arch x86_64",
                "-arch arm64",
                "-ObjC++",
                "-std=c++17",
              ],
              "OTHER_LDFLAGS": [
                "-arch x86_64",
                "-arch arm64",
              ],
            },
          }
        ],
        [
          'OS=="win"',
          {
            "sources": [
              "src/trash_win32.cc"
            ],
            "msvs_settings": {
              "VCCLCompilerTool": {
                "AdditionalOptions": ["/std:c++17"]
              }
            },
          }
        ],
      ]
    }
  ]
}
