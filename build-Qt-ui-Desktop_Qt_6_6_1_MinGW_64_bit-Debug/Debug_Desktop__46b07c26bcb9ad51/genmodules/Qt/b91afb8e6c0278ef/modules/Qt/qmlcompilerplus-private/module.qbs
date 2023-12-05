import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QmlCompilerPlus"
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
    libNameForLinkerDebug: "Qt6QmlCompilerPlus"
    libNameForLinkerRelease: "Qt6QmlCompilerPlus"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QmlCompilerPlus.a"
    pluginTypes: []
    moduleConfig: ["static"]
    cpp.defines: ["QT_QMLCOMPILERPLUS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQmlCompilerPlus","C:/Qt/6.6.1/mingw_64/include/QtQmlCompilerPlus/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQmlCompilerPlus/6.6.1/QtQmlCompilerPlus"]
    cpp.libraryPaths: []
    isStaticLibrary: true
    Group {
        files: [Qt["qmlcompilerplus-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
