import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Protobuf"
    Depends { name: "Qt"; submodules: ["core-private","protobuf"]}

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
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtProtobuf/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtProtobuf/6.6.1/QtProtobuf"]
    cpp.libraryPaths: []
    
}
