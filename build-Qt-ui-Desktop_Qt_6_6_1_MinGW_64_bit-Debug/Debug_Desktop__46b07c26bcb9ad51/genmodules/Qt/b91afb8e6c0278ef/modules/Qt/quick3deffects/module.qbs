import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DEffects"
    Depends { name: "Qt"; submodules: ["qml","quick","quick3d-private"]}

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
    libNameForLinkerDebug: "Qt6Quick3DEffects"
    libNameForLinkerRelease: "Qt6Quick3DEffects"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DEffects.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DEFFECTS_LIB"]
    cpp.systemIncludePaths: []
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3deffects"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
