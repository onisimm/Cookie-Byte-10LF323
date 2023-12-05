import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Quick3DParticleEffects"
    Depends { name: "Qt"; submodules: ["core","gui","qml","quick","quick3druntimerender","quick3dassetimport","quick3d","quick3dparticles"]}

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
    libNameForLinkerDebug: "Qt6Quick3DParticleEffects"
    libNameForLinkerRelease: "Qt6Quick3DParticleEffects"
    libFilePathDebug: undefined
    libFilePathRelease: "C:/Qt/6.6.1/mingw_64/lib/libQt6Quick3DParticleEffects.a"
    pluginTypes: []
    moduleConfig: ["shared"]
    cpp.defines: ["QT_QUICK3DPARTICLEEFFECTS_LIB"]
    cpp.systemIncludePaths: []
    cpp.libraryPaths: []
    Group {
        files: [Qt["quick3dparticleeffects"].libFilePath]
        filesAreTargets: true
        fileTags: ["dynamiclibrary_import"]
    }
}
