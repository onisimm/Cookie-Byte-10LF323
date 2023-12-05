import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "SvgWidgets"
    Depends { name: "Qt"; submodules: ["core","gui","svg","widgets"]}

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
    libNameForLinkerDebug: "Qt6SvgWidgets"
    libNameForLinkerRelease: "Qt6SvgWidgets"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6SvgWidgets.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_SVGWIDGETS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtSvgWidgets"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["svgwidgets"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
