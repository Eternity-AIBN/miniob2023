#include "util/typecast.h"
#include <cassert>

cast_func_ptr cast_to[AttrType::BOOLEANS + 1][AttrType::BOOLEANS + 1] = {{
                                                                         // UNDEFINED
                                                                         not_support,
                                                                         not_support,
                                                                         not_support,
                                                                         not_support,
                                                                         not_support,
                                                                         not_support,
                                                                         not_support,
                                                                     },
    {
        // CHARS
        not_support,
        char_to_char,
        char_to_int,
        char_to_float,
        not_support,
        not_support,
        not_support,
    },
    {
        // INTS
        not_support,
        int_to_char,
        int_to_int,
        int_to_float,
        not_support,
        not_support,
        not_support,
    },
    {
        // FLOATS
        not_support,
        float_to_char,
        float_to_int,
        float_to_float,
        not_support,
        not_support,
        not_support,
    },
    {
        // DATES
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
    },
    {
        // NULLS
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
    },
    {
        // BOOLEANS
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
        not_support,
    }};

bool type_cast_not_support(AttrType i, AttrType j)
{
  return cast_to[i][j] == not_support;
}

void *not_support(void *src)
{
  return nullptr;
}

void *int_to_int(void *src)
{
  assert(nullptr != src);
  void *res = malloc(sizeof(int));
  memcpy(res, (int *)src, sizeof(int));
  return res;
}

void *int_to_float(void *src)
{
  assert(nullptr != src);
  void *res = malloc(sizeof(float));
  float tmp = *(int *)src;
  memcpy(res, &tmp, sizeof(float));
  return res;
}

void *int_to_char(void *src)
{
  std::string str = std::to_string(*(int *)src);
  return strdup(str.c_str());
}

void *float_to_int(void *src)
{
  assert(nullptr != src);
  void *res = malloc(sizeof(int));
  int tmp = *(float *)src + 0.5;
  memcpy(res, &tmp, sizeof(int));
  return res;
}

std::string double2string(double v)
{
  char buf[256];
  snprintf(buf, sizeof(buf), "%.2f", v);
  size_t len = strlen(buf);
  while (buf[len - 1] == '0') {
    len--;
  }
  if (buf[len - 1] == '.') {
    len--;
  }

  return std::string(buf, len);
}

void *float_to_char(void *src)
{
  std::string str = double2string(*(float *)src);
  return strdup(str.c_str());
}

void *float_to_float(void *src)
{
  assert(nullptr != src);
  void *res = malloc(sizeof(float));
  memcpy(res, (float *)src, sizeof(float));
  return res;
}

// make sure char* end with \0
void *char_to_int(void *src)
{
  assert(nullptr != src);
  void *res = malloc(sizeof(int));
  int tmp = atoi((char *)src);
  memcpy(res, &tmp, sizeof(int));
  return res;
}

void *char_to_float(void *src)
{
  assert(nullptr != src);
  void *res = malloc(sizeof(float));
  float tmp = atof((char *)src);
  memcpy(res, &tmp, sizeof(float));
  return res;
}

void *char_to_char(void *src)
{
  return strdup((char *)src);
}

// RC cast_value(const Value &value, FieldMeta *field, Value &ret)
// {
//   // do typecast
//   void *tmp_data = nullptr;
//   tmp_data = cast_to[value.attr_type()][field->type()](value.get_data());  // nullptr or new memory
//   if (nullptr == tmp_data) {
//     LOG_ERROR("Invalid value type. field name=%s, type=%d, but given=%d", field->name(), field->type(), value.attr_type());
//     return RC::SCHEMA_FIELD_TYPE_MISMATCH;
//   }
//   ret.set_type(value.attr_type());

//   int copy_len = field->len();
//   if (field->type() == CHARS) {
//     const int data_len = strlen((const char *)tmp_data);
//     if (copy_len > data_len) {
//       copy_len = data_len + 1;
//     }
//   }

//   ret.set_data((char *)tmp_data, copy_len);
//   return RC::SUCCESS;
// }
