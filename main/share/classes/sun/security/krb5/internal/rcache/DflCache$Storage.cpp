#include <sun/security/krb5/internal/rcache/DflCache$Storage.h>

#include <java/io/IOException.h>
#include <java/lang/Array.h>
#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/InnerClassInfo.h>
#include <java/lang/Integer.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/NullPointerException.h>
#include <java/lang/String.h>
#include <java/lang/Throwable.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/nio/BufferUnderflowException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/ByteOrder.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/SeekableByteChannel.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardCopyOption.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/nio/file/attribute/PosixFilePermission.h>
#include <java/util/AbstractSet.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <sun/security/krb5/internal/KerberosTime.h>
#include <sun/security/krb5/internal/Krb5.h>
#include <sun/security/krb5/internal/KrbApErrException.h>
#include <sun/security/krb5/internal/rcache/AuthTime.h>
#include <sun/security/krb5/internal/rcache/AuthTimeWithHash.h>
#include <sun/security/krb5/internal/rcache/DflCache.h>
#include <jcpp.h>

#undef ATOMIC_MOVE
#undef CREATE
#undef GROUP_EXECUTE
#undef GROUP_READ
#undef GROUP_WRITE
#undef KRB_AP_ERR_REPEAT
#undef OTHERS_EXECUTE
#undef OTHERS_READ
#undef OTHERS_WRITE
#undef OWNER_READ
#undef OWNER_WRITE
#undef READ
#undef REPLACE_EXISTING
#undef TRUNCATE_EXISTING
#undef WRITE

using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $Closeable = ::java::io::Closeable;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $BufferUnderflowException = ::java::nio::BufferUnderflowException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ByteOrder = ::java::nio::ByteOrder;
using $Channel = ::java::nio::channels::Channel;
using $SeekableByteChannel = ::java::nio::channels::SeekableByteChannel;
using $CopyOption = ::java::nio::file::CopyOption;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $StandardCopyOption = ::java::nio::file::StandardCopyOption;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $FileAttribute = ::java::nio::file::attribute::FileAttribute;
using $PosixFilePermission = ::java::nio::file::attribute::PosixFilePermission;
using $AbstractSet = ::java::util::AbstractSet;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;
using $KerberosTime = ::sun::security::krb5::internal::KerberosTime;
using $Krb5 = ::sun::security::krb5::internal::Krb5;
using $KrbApErrException = ::sun::security::krb5::internal::KrbApErrException;
using $AuthTime = ::sun::security::krb5::internal::rcache::AuthTime;
using $AuthTimeWithHash = ::sun::security::krb5::internal::rcache::AuthTimeWithHash;
using $DflCache = ::sun::security::krb5::internal::rcache::DflCache;

namespace sun {
	namespace security {
		namespace krb5 {
			namespace internal {
				namespace rcache {

$FieldInfo _DflCache$Storage_FieldInfo_[] = {
	{"chan", "Ljava/nio/channels/SeekableByteChannel;", nullptr, 0, $field(DflCache$Storage, chan)},
	{}
};

$MethodInfo _DflCache$Storage_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(DflCache$Storage::*)()>(&DflCache$Storage::init$))},
	{"append", "(Lsun/security/krb5/internal/rcache/AuthTimeWithHash;)V", nullptr, $PRIVATE, $method(static_cast<void(DflCache$Storage::*)($AuthTimeWithHash*)>(&DflCache$Storage::append)), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"create", "(Ljava/nio/file/Path;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Path*)>(&DflCache$Storage::create)), "java.io.IOException"},
	{"createNoClose", "(Ljava/nio/file/Path;)Ljava/nio/channels/SeekableByteChannel;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$SeekableByteChannel*(*)($Path*)>(&DflCache$Storage::createNoClose)), "java.io.IOException"},
	{"expunge", "(Ljava/nio/file/Path;Lsun/security/krb5/internal/KerberosTime;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Path*,$KerberosTime*)>(&DflCache$Storage::expunge)), "java.io.IOException"},
	{"loadAndCheck", "(Ljava/nio/file/Path;Lsun/security/krb5/internal/rcache/AuthTimeWithHash;Lsun/security/krb5/internal/KerberosTime;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(DflCache$Storage::*)($Path*,$AuthTimeWithHash*,$KerberosTime*)>(&DflCache$Storage::loadAndCheck)), "java.io.IOException,sun.security.krb5.internal.KrbApErrException"},
	{"makeMine", "(Ljava/nio/file/Path;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Path*)>(&DflCache$Storage::makeMine)), "java.io.IOException"},
	{"readHeader", "(Ljava/nio/channels/SeekableByteChannel;)I", nullptr, $PRIVATE | $STATIC, $method(static_cast<int32_t(*)($SeekableByteChannel*)>(&DflCache$Storage::readHeader)), "java.io.IOException"},
	{}
};

$InnerClassInfo _DflCache$Storage_InnerClassesInfo_[] = {
	{"sun.security.krb5.internal.rcache.DflCache$Storage", "sun.security.krb5.internal.rcache.DflCache", "Storage", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _DflCache$Storage_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.krb5.internal.rcache.DflCache$Storage",
	"java.lang.Object",
	"java.io.Closeable",
	_DflCache$Storage_FieldInfo_,
	_DflCache$Storage_MethodInfo_,
	nullptr,
	nullptr,
	_DflCache$Storage_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.krb5.internal.rcache.DflCache"
};

$Object* allocate$DflCache$Storage($Class* clazz) {
	return $of($alloc(DflCache$Storage));
}

void DflCache$Storage::init$() {
}

void DflCache$Storage::create($Path* p) {
	$init(DflCache$Storage);
	{
		$var($SeekableByteChannel, newChan, createNoClose(p));
		{
			if (newChan != nullptr) {
				newChan->close();
			}
		}
	}
	makeMine(p);
}

void DflCache$Storage::makeMine($Path* p) {
	$init(DflCache$Storage);
	try {
		$var($Set, attrs, $new($HashSet));
		$init($PosixFilePermission);
		attrs->add($PosixFilePermission::OWNER_READ);
		attrs->add($PosixFilePermission::OWNER_WRITE);
		$Files::setPosixFilePermissions(p, attrs);
	} catch ($UnsupportedOperationException&) {
		$catch();
	}
}

$SeekableByteChannel* DflCache$Storage::createNoClose($Path* p) {
	$init(DflCache$Storage);
		$init($StandardOpenOption);
	$var($SeekableByteChannel, newChan, $Files::newByteChannel(p, $$new($OpenOptionArray, {
		static_cast<$OpenOption*>($StandardOpenOption::CREATE),
		static_cast<$OpenOption*>($StandardOpenOption::TRUNCATE_EXISTING),
		static_cast<$OpenOption*>($StandardOpenOption::WRITE)
	})));
	$var($ByteBuffer, buffer, $ByteBuffer::allocate(6));
	$nc(buffer)->putShort((int16_t)1281);
	buffer->order($($ByteOrder::nativeOrder()));
	buffer->putInt($KerberosTime::getDefaultSkew());
	buffer->flip();
	$nc(newChan)->write(buffer);
	return newChan;
}

void DflCache$Storage::expunge($Path* p, $KerberosTime* currTime) {
	$init(DflCache$Storage);
	$var($Path, p2, $Files::createTempFile($($nc(p)->getParent()), "rcache"_s, nullptr, $$new($FileAttributeArray, 0)));
	{
		$var($SeekableByteChannel, oldChan, $Files::newByteChannel(p, $$new($OpenOptionArray, 0)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($SeekableByteChannel, newChan, createNoClose(p2));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								int32_t var$2 = $nc(currTime)->getSeconds();
								int64_t timeLimit = var$2 - readHeader(oldChan);
								while (true) {
									try {
										$var($AuthTime, at, $AuthTime::readFrom(oldChan));
										if ($nc(at)->ctime > timeLimit) {
											$var($ByteBuffer, bb, $ByteBuffer::wrap($(at->encode(true))));
											$nc(newChan)->write(bb);
										}
									} catch ($BufferUnderflowException&) {
										$var($BufferUnderflowException, e, $catch());
										break;
									}
								}
							} catch ($Throwable&) {
								$var($Throwable, t$, $catch());
								if (newChan != nullptr) {
									try {
										newChan->close();
									} catch ($Throwable&) {
										$var($Throwable, x2, $catch());
										t$->addSuppressed(x2);
									}
								}
								$throw(t$);
							}
						} catch ($Throwable&) {
							$assign(var$1, $catch());
						} /*finally*/ {
							if (newChan != nullptr) {
								newChan->close();
							}
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable&) {
					$var($Throwable, t$, $catch());
					if (oldChan != nullptr) {
						try {
							oldChan->close();
						} catch ($Throwable&) {
							$var($Throwable, x2, $catch());
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable&) {
				$assign(var$0, $catch());
			} /*finally*/ {
				if (oldChan != nullptr) {
					oldChan->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	makeMine(p2);
		$init($StandardCopyOption);
	$Files::move(p2, p, $$new($CopyOptionArray, {
		static_cast<$CopyOption*>($StandardCopyOption::REPLACE_EXISTING),
		static_cast<$CopyOption*>($StandardCopyOption::ATOMIC_MOVE)
	}));
}

int32_t DflCache$Storage::loadAndCheck($Path* p, $AuthTimeWithHash* time, $KerberosTime* currTime) {
	int32_t missed = 0;
	if ($Files::isSymbolicLink(p)) {
		$throwNew($IOException, "Symlink not accepted"_s);
	}
	try {
		$var($Set, perms, $Files::getPosixFilePermissions(p, $$new($LinkOptionArray, 0)));
		$init($DflCache);
		if ($DflCache::uid != -1 && $nc(($cast($Integer, $($Files::getAttribute(p, "unix:uid"_s, $$new($LinkOptionArray, 0))))))->intValue() != $DflCache::uid) {
			$throwNew($IOException, "Not mine"_s);
		}
		$init($PosixFilePermission);
		bool var$4 = $nc(perms)->contains($PosixFilePermission::GROUP_READ);
		bool var$3 = var$4 || $nc(perms)->contains($PosixFilePermission::GROUP_WRITE);
		bool var$2 = var$3 || $nc(perms)->contains($PosixFilePermission::GROUP_EXECUTE);
		bool var$1 = var$2 || $nc(perms)->contains($PosixFilePermission::OTHERS_READ);
		bool var$0 = var$1 || $nc(perms)->contains($PosixFilePermission::OTHERS_WRITE);
		if (var$0 || $nc(perms)->contains($PosixFilePermission::OTHERS_EXECUTE)) {
			$throwNew($IOException, "Accessible by someone else"_s);
		}
	} catch ($UnsupportedOperationException&) {
		$catch();
	}
		$init($StandardOpenOption);
	$set(this, chan, $Files::newByteChannel(p, $$new($OpenOptionArray, {
		static_cast<$OpenOption*>($StandardOpenOption::WRITE),
		static_cast<$OpenOption*>($StandardOpenOption::READ)
	})));
	int32_t var$5 = $nc(currTime)->getSeconds();
	int64_t timeLimit = var$5 - readHeader(this->chan);
	int64_t pos = 0;
	bool seeNewButNotSame = false;
	while (true) {
		try {
			pos = $nc(this->chan)->position();
			$var($AuthTime, a, $AuthTime::readFrom(this->chan));
			if ($instanceOf($AuthTimeWithHash, a)) {
				if ($nc(time)->equals(a)) {
					$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_REPEAT);
				} else if (time->sameTimeDiffHash($cast($AuthTimeWithHash, a))) {
					seeNewButNotSame = true;
				}
			} else if (time->isSameIgnoresHash(a)) {
				if (!seeNewButNotSame) {
					$throwNew($KrbApErrException, $Krb5::KRB_AP_ERR_REPEAT);
				}
			}
			if ($nc(a)->ctime < timeLimit) {
				++missed;
			} else {
				--missed;
			}
		} catch ($BufferUnderflowException&) {
			$var($BufferUnderflowException, e, $catch());
			$nc(this->chan)->position(pos);
			break;
		}
	}
	return missed;
}

int32_t DflCache$Storage::readHeader($SeekableByteChannel* chan) {
	$init(DflCache$Storage);
	$var($ByteBuffer, bb, $ByteBuffer::allocate(6));
	$nc(chan)->read(bb);
	if ($nc(bb)->getShort(0) != 1281) {
		$throwNew($IOException, "Not correct rcache version"_s);
	}
	$nc(bb)->order($($ByteOrder::nativeOrder()));
	return bb->getInt(2);
}

void DflCache$Storage::append($AuthTimeWithHash* at) {
	$var($ByteBuffer, bb, nullptr);
	$assign(bb, $ByteBuffer::wrap($($nc(at)->encode(true))));
	$nc(this->chan)->write(bb);
	$assign(bb, $ByteBuffer::wrap($($nc(at)->encode(false))));
	$nc(this->chan)->write(bb);
}

void DflCache$Storage::close() {
	if (this->chan != nullptr) {
		$nc(this->chan)->close();
	}
	$set(this, chan, nullptr);
}

DflCache$Storage::DflCache$Storage() {
}

$Class* DflCache$Storage::load$($String* name, bool initialize) {
	$loadClass(DflCache$Storage, name, initialize, &_DflCache$Storage_ClassInfo_, allocate$DflCache$Storage);
	return class$;
}

$Class* DflCache$Storage::class$ = nullptr;

				} // rcache
			} // internal
		} // krb5
	} // security
} // sun