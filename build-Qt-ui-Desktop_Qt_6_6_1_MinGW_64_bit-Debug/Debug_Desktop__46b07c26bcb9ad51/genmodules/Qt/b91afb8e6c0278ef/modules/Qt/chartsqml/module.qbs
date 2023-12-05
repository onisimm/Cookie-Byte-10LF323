import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "ChartsQml"
    Depends { name: "Qt"; submodules: ["charts","core","gui","qml","quick","opengl"]}

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
    libNameForLinkerDebug: "Qt6ChartsQml"
    libNameForLinkerRelease: "Qt6ChartsQml"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6ChartsQml.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_CHARTSQML_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtChartsQml"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["chartsqml"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
