import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "QuickEffects"
    Depends { name: "Qt"; submodules: ["core-private","gui-private","qml-private","quick-private"]}

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
    libNameForLinkerDebug: "Qt6QuickEffects"
    libNameForLinkerRelease: "Qt6QuickEffects"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6QuickEffects.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICKEFFECTS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuickEffects","C:/Qt/6.6.1/mingw_64/include/QtQuickEffects/6.6.1","C:/Qt/6.6.1/mingw_64/include/QtQuickEffects/6.6.1/QtQuickEffects"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quickeffects-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
