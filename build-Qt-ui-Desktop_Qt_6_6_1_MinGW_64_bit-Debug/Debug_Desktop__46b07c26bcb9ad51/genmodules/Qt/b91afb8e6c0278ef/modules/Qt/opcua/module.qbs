import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "OpcUa"
    Depends { name: "Qt"; submodules: ["core","network"]}

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
    libNameForLinkerDebug: "Qt6OpcUa"
    libNameForLinkerRelease: "Qt6OpcUa"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6OpcUa.a"
    pluginTypes: ["opcua"]
    moduleConfig: ["shared"]
    cpp.defines: ["QT_OPCUA_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtOpcUa"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["opcua"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
