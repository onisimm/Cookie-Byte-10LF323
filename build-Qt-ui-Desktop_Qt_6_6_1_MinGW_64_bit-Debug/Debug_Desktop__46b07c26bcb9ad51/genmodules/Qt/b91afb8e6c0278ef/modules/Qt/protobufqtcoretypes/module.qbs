import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ProtobufQtCoreTypes"
    Depends { name: "Qt"; submodules: []}

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
    libNameForLinkerDebug: "Qt6ProtobufQtCoreTypes"
    libNameForLinkerRelease: "Qt6ProtobufQtCoreTypes"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6ProtobufQtCoreTypes.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_PROTOBUFQTCORETYPES_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtProtobufQtCoreTypes"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["protobufqtcoretypes"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
