import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickLayouts"
    Depends { name: "Qt"; submodules: ["core","gui-private","quick-private","qml"]}

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
    libNameForLinkerDebug: "Qt6QuickLayouts"
    libNameForLinkerRelease: "Qt6QuickLayouts"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QuickLayouts.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICKLAYOUTS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuickLayouts"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quicklayouts"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
