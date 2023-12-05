import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlDebug"
    Depends { name: "Qt"; submodules: ["core-private","network","packetprotocol-private","qml-private"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: []
    staticLibsRelease: ["ws2_32","shell32"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt6QmlDebug"
    libNameForLinkerRelease: "Qt6QmlDebug"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlDebug.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QMLDEBUG_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlDebug","C:/Qt/6.6.1/mingw_64/include/QtQmlDebug/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQmlDebug/6.6.1/QtQmlDebug"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["qmldebug-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
