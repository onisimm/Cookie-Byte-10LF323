import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlLS"
    Depends { name: "Qt"; submodules: ["languageserver-private","core-private","qmldom-private","qmlcompiler-private","qmltoolingsettings-private","languageserver-private"]}

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
    libNameForLinkerDebug: "Qt6QmlLS"
    libNameForLinkerRelease: "Qt6QmlLS"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlLS.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QMLLS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlLS","C:/Qt/6.6.1/mingw_64/include/QtQmlLS/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQmlLS/6.6.1/QtQmlLS"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["qmlls-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
