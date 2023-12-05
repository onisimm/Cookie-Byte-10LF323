import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3D"
    Depends { name: "Qt"; submodules: ["core","gui","qml","quick","quick3druntimerender"]}

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
    libNameForLinkerDebug: "Qt6Quick3D"
    libNameForLinkerRelease: "Qt6Quick3D"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3D.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3D_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3D"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3d"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
