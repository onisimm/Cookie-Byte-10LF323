import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "HttpServer"
    Depends { name: "Qt"; submodules: ["core","network","websockets"]}

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
    libNameForLinkerDebug: "Qt6HttpServer"
    libNameForLinkerRelease: "Qt6HttpServer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6HttpServer.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_HTTPSERVER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtHttpServer"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["httpserver"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
