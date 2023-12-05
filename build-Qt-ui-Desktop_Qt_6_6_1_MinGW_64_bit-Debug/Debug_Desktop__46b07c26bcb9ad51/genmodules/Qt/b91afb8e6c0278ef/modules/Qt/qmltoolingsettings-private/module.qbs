import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlToolingSettings"
    Depends { name: "Qt"; submodules: ["core"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6QmlToolingSettings"
    libNameForLinkerRelease: "Qt6QmlToolingSettings"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlToolingSettings.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QMLTOOLINGSETTINGS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlToolingSettings","C:/Qt/6.6.1/mingw_64/include/QtQmlToolingSettings/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQmlToolingSettings/6.6.1/QtQmlToolingSettings"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["qmltoolingsettings-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
