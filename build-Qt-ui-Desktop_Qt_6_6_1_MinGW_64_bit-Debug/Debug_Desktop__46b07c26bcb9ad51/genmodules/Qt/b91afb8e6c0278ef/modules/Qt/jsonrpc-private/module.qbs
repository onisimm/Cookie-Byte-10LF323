import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "JsonRpc"
    Depends { name: "Qt"; submodules: ["core"]}

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
    libNameForLinkerDebug: "Qt6JsonRpc"
    libNameForLinkerRelease: "Qt6JsonRpc"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6JsonRpc.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_JSONRPC_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtJsonRpc","C:/Qt/6.6.1/mingw_64/include/QtJsonRpc/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtJsonRpc/6.6.1/QtJsonRpc"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["jsonrpc-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
