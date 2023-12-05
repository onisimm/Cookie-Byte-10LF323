import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "WebViewQuick"
    Depends { name: "Qt"; submodules: ["quick","qmlmodels","opengl"]}

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
    libNameForLinkerDebug: "Qt6WebViewQuick"
    libNameForLinkerRelease: "Qt6WebViewQuick"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6WebViewQuick.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_WEBVIEWQUICK_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtWebViewQuick"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["webviewquick"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
