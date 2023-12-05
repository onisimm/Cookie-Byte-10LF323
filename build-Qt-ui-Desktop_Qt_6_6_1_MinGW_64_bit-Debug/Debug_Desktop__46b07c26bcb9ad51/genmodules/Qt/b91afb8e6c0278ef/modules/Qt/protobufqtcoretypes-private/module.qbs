import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ProtobufQtCoreTypes"
    Depends { name: "Qt"; submodules: ["protobufqtcoretypes"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: false
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
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtProtobufQtCoreTypes/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtProtobufQtCoreTypes/6.6.1/QtProtobufQtCoreTypes"]
    cpp.libraryPaths: []
    
}
