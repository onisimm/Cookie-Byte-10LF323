import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "OpcUa"
    Depends { name: "Qt"; submodules: ["core-private","network-private","opcua"]}

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
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtOpcUa/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtOpcUa/6.6.1/QtOpcUa"]
    cpp.libraryPaths: []
    
}
