import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "LanguageServer"
    Depends { name: "Qt"; submodules: ["core-private","jsonrpc-private"]}

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
    libNameForLinkerDebug: "Qt6LanguageServer"
    libNameForLinkerRelease: "Qt6LanguageServer"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6LanguageServer.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_LANGUAGESERVER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtLanguageServer","C:/Qt/6.6.1/mingw_64/include/QtLanguageServer/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtLanguageServer/6.6.1/QtLanguageServer"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["languageserver-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
