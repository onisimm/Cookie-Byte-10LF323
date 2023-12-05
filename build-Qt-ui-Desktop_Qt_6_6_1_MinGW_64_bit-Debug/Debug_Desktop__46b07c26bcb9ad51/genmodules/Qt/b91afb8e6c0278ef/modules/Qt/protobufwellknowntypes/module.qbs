import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ProtobufWellKnownTypes"
    Depends { name: "Qt"; submodules: ["protobuf"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6ProtobufWellKnownTypes"
    libNameForLinkerRelease: "Qt6ProtobufWellKnownTypes"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6ProtobufWellKnownTypes.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_PROTOBUFWELLKNOWNTYPES_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtProtobufWellKnownTypes"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["protobufwellknowntypes"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
