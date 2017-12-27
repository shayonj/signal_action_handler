require "mkmf"

abort "missing rb_hash_new()"   unless have_func "rb_hash_new"

create_makefile "signal_action_handler/signal_action_handler"
