{
  "targets": [
    {
      "target_name": "assimp2json",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": ["../node-binding/a2j_node_js.cpp",
		"../node-binding/AssimpToJson.cpp",
		"../assimp2json/json_exporter.cpp",
		"../assimp2json/cencode.c",
		"../assimp2json/mesh_splitter.cpp"],
      "include_dirs": [
        "../assimp2json",
      	"../assimp/include"],
      	"libraries": ["-Wl,-rpath", "-L../bin", "-lassimpd"]
    }
  ]
}
