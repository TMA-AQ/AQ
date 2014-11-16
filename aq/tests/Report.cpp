#include "Report.h"
#include <iostream>

namespace aq
{
	namespace 
	{
		void write_query(std::ostream& report, const aq::core::SelectStatement& ss)
		{
			report << "<sql>" << std::endl;
			report << ss.to_string() << std::endl;
			report << "</sql>" << std::endl;

			report << "<aql>" << std::endl;
			report << ss.to_string(aq::core::SelectStatement::output_t::AQL) << std::endl;
			report << "</aql>" << std::endl;
		}
	}

	Report::Report(const std::string& _filename)
		: filename(_filename), n_db(0), n_query(0), current_database(false)
	{
		std::cout << "open " << filename << std::endl;
		report.open(filename.c_str(), std::ios::beg | std::ios::out | std::ios::trunc);
		report << "<databases>" << std::endl;
	}

	Report::~Report()
	{
		std::cout << "close " << filename << std::endl;
		if (current_database)
		{
			report << "</queries>" << std::endl;
			report << "</database>" << std::endl;
		}
		report << "</databases>" << std::endl;
		report.close();
	}
	
	void Report::new_db(const DatabaseGenerator::handle_t::tables_t& tables)
	{
		if (current_database)
		{
			n_query = 0;
			report << "</queries>" << std::endl;
			report << "</database>" << std::endl;	
		}
		else
		{
			current_database = true;
		}
		report << "<database id=\"" << ++n_db << "\">" << std::endl;
		for (auto& table : tables)
		{
			report << "<table name=\"" << table.first << "\">" << std::endl;

			// column id
			report << "<column name=\"id\">" << std::endl;
			report << "<values>";
			size_t i = 0;
			while (i < table.second.size())
			{
				report << i++;
				if (i < table.second.size())
					report << ",";
			}
			report << "</values>" << std::endl;
			report << "</column>" << std::endl;
			
			// column values
			report << "<column name=\"v1\">" << std::endl;
			report << "<values>";
			i = 0;
			while (i < table.second.size())
			{
				report << table.second[i];
				i += 1;
				if (i < table.second.size())
					report << ",";
			}
			report << "</values>" << std::endl;
			report << "</column>" << std::endl;

			report << "</table>" << std::endl;
		}
		report << "<queries>" << std::endl;
	}
	
	void Report::new_query(const aq::core::SelectStatement& ss)
	{
		report << "<query id=\"" << ++n_query << "\">" << std::endl;
		write_query(report, ss);
	}
	
	void Report::close_query()
	{
		report << "</query>" << std::endl;
	}
	
	void Report::time_exec(std::string db_name, uint64_t duration_ms)
	{
		report << "<" << db_name << " execution_time=" << duration_ms << "/>" << std::endl;
	}

	void Report::success(const aq::core::SelectStatement& ss)
	{
		report << "<query id=\"" << ++n_query << "\" status=\"success\">" << std::endl;
		write_query(report, ss);
		report << "</query>" << std::endl;
	}

	void Report::error(const aq::core::SelectStatement& ss)
	{
		report << "<query id=\"" << ++n_query << "\" status=\"error\">" << std::endl;
		write_query(report, ss);
		report << "</query>" << std::endl;
	}

}