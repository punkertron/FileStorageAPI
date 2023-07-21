#ifndef CONTENTTYPE_HPP
#define CONTENTTYPE_HPP

#include <iostream>

#include "crow.h"

struct ContentType {
    struct context {};

    void before_handle(crow::request& req, crow::response& res, context& ctx) {
        std::string content_type;

        if (req.headers.count("Content-Type") == 0 ||
            (content_type = req.get_header_value("Content-Type")) !=
                "application/json") {
            res.code = crow::status::BAD_REQUEST;
            res.end();
            return;
        }
        (void)ctx;
    }

    void after_handle(crow::request& req, crow::response& res, context& ctx) {
        (void)req;
        (void)res;
        (void)ctx;
    }
};

#endif  // CONTENTTYPE_HPP