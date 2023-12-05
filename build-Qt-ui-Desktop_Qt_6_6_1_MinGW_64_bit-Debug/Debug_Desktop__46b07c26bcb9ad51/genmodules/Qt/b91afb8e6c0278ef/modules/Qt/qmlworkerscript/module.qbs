import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlWorkerScript"
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
    libNameForLinkerDebug: "Qt6QmlWorkerScript"
    libNameForLinkerRelease: "Qt6QmlWorkerScript"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlWorkerScript.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QMLWORKERSCRIPT_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlWorkerScript"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["qmlworkerscript"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
