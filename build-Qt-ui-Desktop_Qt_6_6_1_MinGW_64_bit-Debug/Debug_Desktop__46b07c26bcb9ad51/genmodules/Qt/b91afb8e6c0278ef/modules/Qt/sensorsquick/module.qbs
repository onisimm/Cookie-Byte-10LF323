import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "SensorsQuick"
    Depends { name: "Qt"; submodules: ["core","qml","sensors"]}

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
    libNameForLinkerDebug: "Qt6SensorsQuick"
    libNameForLinkerRelease: "Qt6SensorsQuick"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6SensorsQuick.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_SENSORSQUICK_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtSensorsQuick"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["sensorsquick"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
