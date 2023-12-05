import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxServer"
    Depends { name: "Qt"; submodules: ["axserver"]}

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
    libNameForLinkerDebug: "Qt6AxServer"
    libNameForLinkerRelease: "Qt6AxServer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6AxServer.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: []
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include/QtAxServer/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtAxServer/6.6.1/QtAxServer"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["axserver-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
