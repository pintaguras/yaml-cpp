#ifndef SINGLEDOCPARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define SINGLEDOCPARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <map>
#include <memory>
#include <string>

#include "yaml-cpp/anchor.h"
#include "yaml-cpp/noncopyable.h"

namespace YAML {
class CollectionStack;
class EventHandler;
class Node;
class Scanner;
struct Directives;
struct Mark;
struct Token;

class SingleDocParser : private noncopyable {
 public:
  SingleDocParser(Scanner& scanner, Directives& directives);
  ~SingleDocParser();

  void HandleDocument(EventHandler& eventHandler);

 private:
  void HandleNode(EventHandler& eventHandler);

  void HandleSequence(EventHandler& eventHandler);
  void HandleBlockSequence(EventHandler& eventHandler);
  void HandleFlowSequence(EventHandler& eventHandler);

  void HandleMap(EventHandler& eventHandler);
  void HandleBlockMap(EventHandler& eventHandler);
  void HandleFlowMap(EventHandler& eventHandler);
  void HandleCompactMap(EventHandler& eventHandler);
  void HandleCompactMapWithNoKey(EventHandler& eventHandler);

  void ParseProperties(std::string& tag, anchor_t& anchor, std::string& anchor_string);
  void ParseTag(std::string& tag);
  void ParseAnchor(anchor_t& anchor, std::string & anchor_string);

 private:
  Scanner& m_scanner;
  Directives& m_directives;
  std::unique_ptr<CollectionStack> m_pCollectionStack;
};
}

#endif  // SINGLEDOCPARSER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
