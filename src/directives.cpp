#include "directives.h"

#include "yaml-cpp/exceptions.h"

namespace YAML {
Directives::Directives() : m_curAnchor(0) {
  // version
  version.isDefault = true;
  version.major = 1;
  version.minor = 2;
}

const std::string Directives::TranslateTagHandle(
    const std::string& handle) const {
  std::map<std::string, std::string>::const_iterator it = tags.find(handle);
  if (it == tags.end()) {
    if (handle == "!!")
      return "tag:yaml.org,2002:";
    return handle;
  }

  return it->second;
}


anchor_t Directives::RegisterAnchor(const std::string& name) {
  if (name.empty())
    return NullAnchor;

  return m_anchors[name] = ++m_curAnchor;
}

anchor_t Directives::LookupAnchor(const std::string& name) const {
  Anchors::const_iterator it = m_anchors.find(name);
  if (it == m_anchors.end())
    throw InvalidAnchor();
  return it->second;
}
}
