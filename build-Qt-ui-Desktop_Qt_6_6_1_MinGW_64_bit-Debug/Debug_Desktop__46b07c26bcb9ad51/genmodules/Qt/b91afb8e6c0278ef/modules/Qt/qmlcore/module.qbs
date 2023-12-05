import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlCore"
    Depends { name: "Qt"; submodules: ["core","qml"]}

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
    libNameForLinkerDebug: "Qt6QmlCore"
    libNameForLinkerRelease: "Qt6QmlCore"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlCore.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QMLCORE_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlCore"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["qmlcore"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
