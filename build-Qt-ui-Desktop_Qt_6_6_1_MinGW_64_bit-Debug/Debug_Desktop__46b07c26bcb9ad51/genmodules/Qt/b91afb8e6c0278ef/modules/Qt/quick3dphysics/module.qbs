import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DPhysics"
    Depends { name: "Qt"; submodules: ["core","gui","qml","quick","quick3d"]}

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
    libNameForLinkerDebug: "Qt6Quick3DPhysics"
    libNameForLinkerRelease: "Qt6Quick3DPhysics"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DPhysics.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DPHYSICS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DPhysics"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dphysics"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
