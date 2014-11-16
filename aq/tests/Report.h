#pragma once

#include <string>
#include <fstream>
#include <cstdint>

#include <aq/util/AQLParser.h>

#include "DatabaseGenerator.h"

namespace aq
{

	class Report
	{
	public:
		Report(const std::string& filename);
		~Report();
		void new_db(const DatabaseGenerator::handle_t::tables_t& tables);
		void new_query(const aq::core::SelectStatement& ss);
		void close_query();
		void success(const aq::core::SelectStatement& ss);
		void error(const aq::core::SelectStatement& ss);
		void time_exec(std::string db_name, uint64_t duration_ms);
		std::ofstream report;
	private:
		std::string filename;
		size_t n_db;
		size_t n_query;
		bool current_database;
	};

}