#include "CommandHandler.h"
#include <aq/util/Database.h>
#include <aq/util/Exceptions.h>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>

namespace aq
{

int CommandHandler::process(const std::string& cmd)
{
  if (cmd == "") return 0;
  int rc = 0;
  try
  {

    // split command in several words
    std::vector<std::string> words;
    boost::split(words, cmd, boost::is_any_of(" \n"));
    for (auto& w : words)
    {
      boost::trim(w);
      if ((w.size() >= 3) && ((*w.begin()) == '\'') && ((*w.rbegin()) == '\''))
        w = w.substr(1, w.size() - 2);
    }
    std::string::size_type pos = (*words.rbegin()).find(';');
    if (pos != std::string::npos)
    {
      (*words.rbegin()).erase(pos);
    }

    // process command
    if (words.size() >= 2 && boost::iequals(words[0], "SHOW"))
    {
      if (boost::iequals(words[1], "TABLES"))
      {
        for (auto& table : baseDesc->getTables())
        {
          std::cout << table->getName() << std::endl;
        }
      }
      else if (boost::iequals(words[1], "DATABASES"))
      {
        boost::filesystem::path p(this->databasesPath);
        if (boost::filesystem::exists(p) && boost::filesystem::is_directory(p))
        {
          boost::filesystem::directory_iterator end_it;
          for (boost::filesystem::directory_iterator it(p); it != end_it; ++it)
          {
            if (boost::filesystem::is_directory(it->status()))
            {
              aq::Database db(it->path().string());
              if (db.isValid())
                std::cout << db.getName() << std::endl;
            }
          }
        }
      }
      else if (boost::iequals(words[1], "VARS"))
      {
        settings->dump(std::cout);
        std::cout << std::endl;
        std::cout << "AQ_ENGINE: " << settings->aqEngine << std::endl;
        std::cout << "ROOT_PATH: " << databasesPath << std::endl;
        std::cout << "DATABASE : " << databaseName << std::endl;
      }
      else if (words.size() >= 3 && boost::iequals(words[1], "VAR"))
      {
        for (size_t i = 2; i < words.size(); i++)
        {
        }
      }
    }
    else if (words.size() >= 1 && boost::iequals(words[0], "DESC"))
    {
      if ((words.size() >= 2) && (words[1] != ""))
      {
        std::string tname = words[1];
        boost::trim(tname);
        auto table = baseDesc->getTable(tname);
        table->dumpRaw(std::cout);
      }
      else
      {
        baseDesc->dumpRaw(std::cout);
      }
    }
    else if (words.size() >= 3 && boost::iequals(words[0], "SET"))
    {
      if (boost::iequals(words[1], "AQ-ENGINE"))
      {
        settings->aqEngine = words[2];
      }
      else if (boost::iequals(words[1], "TRACE"))
      {
        settings->trace = !((words[2] == "0") || boost::iequals(words[2], "FALSE"));
      }
    }
    else if (words.size() >= 2 && boost::iequals(words[0], "CONNECT"))
    {
      databaseName = words[1];
      std::string s = databasesPath + databaseName + "/";
      aq::Database d(s);
      if (d.isValid())
      {
        aq::base_t b = d.getBaseDesc();
        baseDesc->clear();
        baseDesc->loadFromBaseDesc(b);
        settings->initPath(s);
        std::cout << "connected to " << words[1] << std::endl;
      }
      else
      {
        std::cout << "invalid database " << words[1] << std::endl;
      }
    }
    else if (boost::iequals(words[0], "DUMP"))
    {
      if ((words.size() >= 2) && (words[1] != ""))
      {
        std::string tname = words[1];
        boost::trim(tname);
        auto table = baseDesc->getTable(tname);
        std::cout << "TODO" << std::endl;
        // table->dumpRawData(std::cout);
      }
      else
      {
        // for (auto& table : baseDesc->getTables())
        // {
        //   std::cout << "TODO" << std::endl;
        //   table->dumpRawData(std::cout);
        // }
      }
    }
    else
    {
      rc = -1;
    }
    std::cout << std::endl;
  }
  catch (const aq::generic_error& ge)
  {
    std::cout << ge.what() << std::endl << std::endl;
  }
  return rc;
}

}
