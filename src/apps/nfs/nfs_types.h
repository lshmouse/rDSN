/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef nfs_TYPES_H
#define nfs_TYPES_H

#include <dsn/service_api_cpp.h>

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>

namespace dsn { namespace service {

class copy_request;

class copy_response;

class get_file_size_request;

class get_file_size_response;

typedef struct _copy_request__isset {
  _copy_request__isset() : source(false), source_dir(false), dst_dir(false), file_name(false), offset(false), size(false), is_last(false), overwrite(false) {}
  bool source :1;
  bool source_dir :1;
  bool dst_dir :1;
  bool file_name :1;
  bool offset :1;
  bool size :1;
  bool is_last :1;
  bool overwrite :1;
} _copy_request__isset;

class copy_request : public virtual ::apache::thrift::TBase {
 public:

  copy_request(const copy_request&);
  copy_request& operator=(const copy_request&);
  copy_request() : source_dir(), dst_dir(), file_name(), offset(0), size(0), is_last(0), overwrite(0) {
  }

  virtual ~copy_request() throw();
   ::dsn::rpc_address source;
  std::string source_dir;
  std::string dst_dir;
  std::string file_name;
  int64_t offset;
  int32_t size;
  bool is_last;
  bool overwrite;

  _copy_request__isset __isset;

  void __set_source(const  ::dsn::rpc_address& val);

  void __set_source_dir(const std::string& val);

  void __set_dst_dir(const std::string& val);

  void __set_file_name(const std::string& val);

  void __set_offset(const int64_t val);

  void __set_size(const int32_t val);

  void __set_is_last(const bool val);

  void __set_overwrite(const bool val);

  bool operator == (const copy_request & rhs) const
  {
    if (!(source == rhs.source))
      return false;
    if (!(source_dir == rhs.source_dir))
      return false;
    if (!(dst_dir == rhs.dst_dir))
      return false;
    if (!(file_name == rhs.file_name))
      return false;
    if (!(offset == rhs.offset))
      return false;
    if (!(size == rhs.size))
      return false;
    if (!(is_last == rhs.is_last))
      return false;
    if (!(overwrite == rhs.overwrite))
      return false;
    return true;
  }
  bool operator != (const copy_request &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const copy_request & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(copy_request &a, copy_request &b);

inline std::ostream& operator<<(std::ostream& out, const copy_request& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _copy_response__isset {
  _copy_response__isset() : error(false), file_content(false), offset(false), size(false) {}
  bool error :1;
  bool file_content :1;
  bool offset :1;
  bool size :1;
} _copy_response__isset;

class copy_response : public virtual ::apache::thrift::TBase {
 public:

  copy_response(const copy_response&);
  copy_response& operator=(const copy_response&);
  copy_response() : offset(0), size(0) {
  }

  virtual ~copy_response() throw();
   ::dsn::error_code error;
   ::dsn::blob file_content;
  int64_t offset;
  int32_t size;

  _copy_response__isset __isset;

  void __set_error(const  ::dsn::error_code& val);

  void __set_file_content(const  ::dsn::blob& val);

  void __set_offset(const int64_t val);

  void __set_size(const int32_t val);

  bool operator == (const copy_response & rhs) const
  {
    if (!(error == rhs.error))
      return false;
    if (!(file_content == rhs.file_content))
      return false;
    if (!(offset == rhs.offset))
      return false;
    if (!(size == rhs.size))
      return false;
    return true;
  }
  bool operator != (const copy_response &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const copy_response & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(copy_response &a, copy_response &b);

inline std::ostream& operator<<(std::ostream& out, const copy_response& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _get_file_size_request__isset {
  _get_file_size_request__isset() : source(false), dst_dir(false), file_list(false), source_dir(false), overwrite(false) {}
  bool source :1;
  bool dst_dir :1;
  bool file_list :1;
  bool source_dir :1;
  bool overwrite :1;
} _get_file_size_request__isset;

class get_file_size_request : public virtual ::apache::thrift::TBase {
 public:

  get_file_size_request(const get_file_size_request&);
  get_file_size_request& operator=(const get_file_size_request&);
  get_file_size_request() : dst_dir(), source_dir(), overwrite(0) {
  }

  virtual ~get_file_size_request() throw();
   ::dsn::rpc_address source;
  std::string dst_dir;
  std::vector<std::string>  file_list;
  std::string source_dir;
  bool overwrite;

  _get_file_size_request__isset __isset;

  void __set_source(const  ::dsn::rpc_address& val);

  void __set_dst_dir(const std::string& val);

  void __set_file_list(const std::vector<std::string> & val);

  void __set_source_dir(const std::string& val);

  void __set_overwrite(const bool val);

  bool operator == (const get_file_size_request & rhs) const
  {
    if (!(source == rhs.source))
      return false;
    if (!(dst_dir == rhs.dst_dir))
      return false;
    if (!(file_list == rhs.file_list))
      return false;
    if (!(source_dir == rhs.source_dir))
      return false;
    if (!(overwrite == rhs.overwrite))
      return false;
    return true;
  }
  bool operator != (const get_file_size_request &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const get_file_size_request & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(get_file_size_request &a, get_file_size_request &b);

inline std::ostream& operator<<(std::ostream& out, const get_file_size_request& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _get_file_size_response__isset {
  _get_file_size_response__isset() : error(false), file_list(false), size_list(false) {}
  bool error :1;
  bool file_list :1;
  bool size_list :1;
} _get_file_size_response__isset;

class get_file_size_response : public virtual ::apache::thrift::TBase {
 public:

  get_file_size_response(const get_file_size_response&);
  get_file_size_response& operator=(const get_file_size_response&);
  get_file_size_response() : error(0) {
  }

  virtual ~get_file_size_response() throw();
  int32_t error;
  std::vector<std::string>  file_list;
  std::vector<int64_t>  size_list;

  _get_file_size_response__isset __isset;

  void __set_error(const int32_t val);

  void __set_file_list(const std::vector<std::string> & val);

  void __set_size_list(const std::vector<int64_t> & val);

  bool operator == (const get_file_size_response & rhs) const
  {
    if (!(error == rhs.error))
      return false;
    if (!(file_list == rhs.file_list))
      return false;
    if (!(size_list == rhs.size_list))
      return false;
    return true;
  }
  bool operator != (const get_file_size_response &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const get_file_size_response & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(get_file_size_response &a, get_file_size_response &b);

inline std::ostream& operator<<(std::ostream& out, const get_file_size_response& obj)
{
  obj.printTo(out);
  return out;
}

}} // namespace

#endif
