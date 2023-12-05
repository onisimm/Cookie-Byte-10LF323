import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ProtobufQtGuiTypes"
    Depends { name: "Qt"; submodules: ["protobufqtguitypes"]}

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
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtProtobufQtGuiTypes/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtProtobufQtGuiTypes/6.6.1/QtProtobufQtGuiTypes"]
    cpp.libraryPaths: []
    
}
