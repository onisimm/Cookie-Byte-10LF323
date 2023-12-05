import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlCompiler"
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
    libNameForLinkerDebug: "Qt6QmlCompiler"
    libNameForLinkerRelease: "Qt6QmlCompiler"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlCompiler.a"
    pluginTypes: ["qmllint"]
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QMLCOMPILER_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlCompiler"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["qmlcompiler"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
