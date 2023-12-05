import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DPhysicsHelpers"
    Depends { name: "Qt"; submodules: ["qml","quick","quick3d"]}

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
    libNameForLinkerDebug: "Qt6Quick3DPhysicsHelpers"
    libNameForLinkerRelease: "Qt6Quick3DPhysicsHelpers"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DPhysicsHelpers.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DPHYSICSHELPERS_LIB"]
    cpp.systemIncludePaths: ["C:/Qt/6.6.1/mingw_64/include","C:/Qt/6.6.1/mingw_64/include/QtQuick3DPhysicsHelpers"]
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dphysicshelpers"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
