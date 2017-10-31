#ifndef DIRECTIVES_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define DIRECTIVES_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <string>
#include <map>

#include "yaml-cpp/anchor.h"

namespace YAML {
struct Version {
  bool isDefault;
  int major, minor;
};

struct Directives {
  Directives();

  const std::string TranslateTagHandle(const std::string& handle) const;

  Version version;
  std::map<std::string, std::string> tags;

  anchor_t RegisterAnchor(const std::string& name);
  anchor_t LookupAnchor(const std::string& name) const;

  typedef std::map<std::string, anchor_t> Anchors;
  Anchors m_anchors;
  anchor_t m_curAnchor;
};
}

#endif  // DIRECTIVES_H_62B23520_7C8E_11DE_8A39_0800200C9A66
