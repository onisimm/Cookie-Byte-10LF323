import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ProtobufQtGuiTypes"
    Depends { name: "Qt"; submodules: ["protobufqtcoretypes"]}

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
    libNameForLinkerDebug: "Qt6ProtobufQtGuiTypes"
    libNameForLinkerRelease: "Qt6ProtobufQtGuiTypes"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6ProtobufQtGuiTypes.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_PROTOBUFQTGUITYPES_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtProtobufQtGuiTypes"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["protobufqtguitypes"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
