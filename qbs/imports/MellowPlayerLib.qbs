import qbs


Product {
    id: product
    
    property string layer: ""

    name: "MellowPlayer." + layer
    type: platform.libraryType
    
    cpp.includePaths: [ product.sourceDirectory + "/include", project.thridPartyIncludePath,]
    cpp.cxxLanguageVersion: platform.cxxLanguageVersion
    cpp.warningLevel: undefined
    cpp.cxxFlags: platform.cxxFlags
    cpp.treatWarningsAsErrors: false
    cpp.linkerFlags: platform.linkerFlags

    Depends { name: 'cpp' }
    Depends { name: "platform"}
    Depends { name: "Qt.core" }
    Depends { name: "Qt.gui" }
    
    Group {
        name: "Library"
        fileTagsFilter: "dynamiclibrary"
        qbs.install: true
        qbs.installDir: project.libDir
    }

    Group {
        name: "Precompiled headers"
        files: [product.sourceDirectory + "/src/stdafx.hpp"]
        fileTags: ["cpp_pch_src"]
    }
}
