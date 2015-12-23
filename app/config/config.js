{
    "service" : {
        "api" : "http",
        "port" : 8080
    },
    "http" : {
        "script_names" : [ "/hello" ]
    },
    "security" : {
        "csrf" : {
            "enable" : false
        }
    },
    "file_server" : {
        "enable" : true,
        "listing" : true,
        "document_root" : "./uploads"
    }
}
