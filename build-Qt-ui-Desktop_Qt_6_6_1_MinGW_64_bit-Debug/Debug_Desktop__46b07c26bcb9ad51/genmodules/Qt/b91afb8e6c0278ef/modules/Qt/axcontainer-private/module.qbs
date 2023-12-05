import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxContainer"
    Depends { name: "Qt"; submodules: ["axcontainer"]}

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
    libNameForLinkerDebug: "Qt6AxContainer"
    libNameForLinkerRelease: "Qt6AxContainer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6AxContainer.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: []
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtAxContainer/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtAxContainer/6.6.1/QtAxContainer"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["axcontainer-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
