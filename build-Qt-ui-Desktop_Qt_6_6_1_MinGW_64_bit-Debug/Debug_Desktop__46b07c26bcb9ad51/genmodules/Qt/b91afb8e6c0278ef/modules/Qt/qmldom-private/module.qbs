import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlDom"
    Depends { name: "Qt"; submodules: ["qml-private","qmlcompiler-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["mpr","userenv","ws2_32","shell32"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6QmlDom"
    libNameForLinkerRelease: "Qt6QmlDom"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlDom.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QMLDOM_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlDom","C:/Qt/6.6.1/mingw_64/include/QtQmlDom/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQmlDom/6.6.1/QtQmlDom"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["qmldom-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
