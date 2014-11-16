#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <cstdint>
#include <sstream>

// ------------------------------------------------------------------------------
template <typename T>
class Generator
{
public:
  typedef T type;
  
  Generator(T max_value, uint64_t _nEl) : nEl(_nEl) {}
  const char * getType() const { return "LON" ; }
  uint64_t getElSize() const { return sizeof(typename T); }
  uint64_t getNEl() const { return nEl; }
  void gen(T * v) const;
  
private:
  uint64_t max_value;
  uint64_t nEl;
};

template <typename T>
void Generator<T>::gen(T * v) const
{
  for (uint64_t i = 0; i < nEl; ++i)
  {
    v[i] = ::rand() % (uint64_t)max_value;
  }
}

// ------------------------------------------------------------------------------
template <>  
const char * Generator<uint32_t>::getType() const 
{ 
  return "INT" ; 
}

template <>
void Generator<uint32_t>::gen(uint32_t * v) const
{
  for (uint64_t i = 0; i < nEl; ++i)
  {
    v[i] = ::rand() % (uint32_t)max_value;
  }
}

// ------------------------------------------------------------------------------
template <>  
const char * Generator<double>::getType() const 
{ 
  return "DOU" ; 
}

template <>
void Generator<double>::gen(double * v) const
{
  for (uint64_t i = 0; i < nEl; ++i)
  {
    v[i] = (double)(::rand() % (uint64_t)max_value);
  }
}

// ------------------------------------------------------------------------------
template <>  
const char * Generator<char>::getType() const 
{ 
  return "CHA" ; 
}

template <>
void Generator<char>::gen(char * v) const
{
  for (uint64_t i = 0; i < nEl - 1; ++i)
  {
    v[i] = 32 + (::rand() % (127 - 32));
  }
  v[nEl - 1] = 0;
}

// ------------------------------------------------------------------------------
template <class G>
void build_temporary_column(G& g, uint32_t nTable, uint32_t nCol, uint64_t nRow, uint64_t packetSize, const char * path)
{
  typename G::type * v = new typename G::type[g.getNEl()];
  char filename[128];
  FILE * fd = NULL;
  for (uint64_t i = 0; i < nRow; ++i)
  {
    if ((i % packetSize) == 0)
    {
      if (fd != NULL)
      {
        fclose(fd);
      }
      sprintf(filename, "%s/B001TMP%.4uC%.4u%s%.4uP%.12u.TMP", path, nTable, nCol, g.getType(), sizeof(typename G::type) * g.getNEl(), i / packetSize);
      fd = fopen(filename, "wb");
    }
    g.gen(v);
    fwrite(v, sizeof(typename G::type), g.getNEl(), fd);
  }
  fclose(fd);
  delete[] v;
}

// ------------------------------------------------------------------------------
template <typename T>
void build_query_and_temporary_column(std::ostream& query, uint64_t max_value, uint64_t nel, uint64_t size_tmp2, uint64_t size_tmp3, uint64_t packet_size, const std::string& dbPath)
{  
  // temporary columns
  Generator<T> gen((T)max_value, nel);
  build_temporary_column(gen, 2, 1, size_tmp2, packet_size, std::string(dbPath + "data_orga/tmp/test_aq_engine/").c_str());
  build_temporary_column(gen, 3, 1, size_tmp3, packet_size, std::string(dbPath + "data_orga/tmp/test_aq_engine/").c_str());
  std::string type = gen.getType();
  uint64_t columnSize = nel * gen.getElSize();

  // query
  char tmp2[128];
  char tmp3[128];
  char tmp2c1[128];
  char tmp3c1[128];
  sprintf(tmp2, "TMP0002SIZE%.10u", size_tmp2);
  sprintf(tmp3, "TMP0003SIZE%.10u", size_tmp3);
  sprintf(tmp2c1, "C0001%s%.4u", type.c_str(), columnSize);
  sprintf(tmp3c1, "C0001%s%.4u", type.c_str(), columnSize);
  query << " SELECT , . " << tmp2 << " " << tmp2c1 << " . " << tmp3 << " " << tmp3c1 << std::endl;
  query << " FROM , " << tmp2 << " " << tmp3 << std::endl;
  query << " WHERE K_JEQ K_INNER . " << tmp2 << " " << tmp2c1 << " K_INNER . " << tmp3 << " " << tmp3c1 << std::endl;
  query << " GROUP , . " << tmp2 << " " << tmp2c1 << " . " << tmp3 << " " << tmp3c1 << std::endl;
}

#endif