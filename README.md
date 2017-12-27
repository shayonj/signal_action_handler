# SignalActionHandler

List current action handlers for all Signals, without having to override the current action handlers to retrieve the same information. That way, before a signal is raised, you know what the action will be.

## Usage

```ruby
SignalActionHandler.info
 => {
    "EXIT" => "DEFAULT",
    "HUP" => "DEFAULT",
    "INT" => "DEFAULT",
    "QUIT" => "DEFAULT",
    "ILL" => "DEFAULT",
    "TRAP" => "SYSTEM_DEFAULT",
    "ABRT" => "SYSTEM_DEFAULT",
    "IOT" => "SYSTEM_DEFAULT",
    "EMT" => "SYSTEM_DEFAULT",
    "FPE" => "SYSTEM_DEFAULT",
    "KILL" => "SYSTEM_DEFAULT",
    "BUS" => "DEFAULT",
    "SEGV" => "DEFAULT",
    "SYS" => "DEFAULT",
    "PIPE" => "DEFAULT",
    "ALRM" => "DEFAULT",
    "TERM" => "DEFAULT",
    "URG" => "SYSTEM_DEFAULT",
    "STOP" => "SYSTEM_DEFAULT",
    "TSTP" => "SYSTEM_DEFAULT",
    "CONT" => "SYSTEM_DEFAULT",
    "CHLD" => "SYSTEM_DEFAULT",
    "CLD" => "SYSTEM_DEFAULT",
    "TTIN" => "SYSTEM_DEFAULT",
    "TTOU" => "SYSTEM_DEFAULT",
    "IO" => "SYSTEM_DEFAULT",
    "XCPU" => "SYSTEM_DEFAULT",
    "XFSZ" => "SYSTEM_DEFAULT",
    "VTALRM" => "DEFAULT",
    "PROF" => "SYSTEM_DEFAULT",
    "WINCH" => "SYSTEM_DEFAULT",
    "USR1" => "DEFAULT",
    "USR2" => "DEFAULT",
    "INFO" => "SYSTEM_DEFAULT"
    }
```

As a best effort, the values (action handlers) are same as the standard/default ruby's `Signal` values. As descrb

- **DEFAULT**: Ruby’s default handler
- **SYSTEM_DEFAULT**: The operating system’s default handler
- **IGNORE**: The signal will be ignored

Reference: https://ruby-doc.org/core-2.2.0/Signal.html#method-c-trap

## Why not just use `Signal.trap`

`Signal.trap("TERM", "IGNORE")` would return the previous action handler on `TERM`, at the same time would set the *current* action handler to `IGNORE`.

Whereas `SignalActionHandler.info["TERM"]` would return the *current* action handler on `TERM`. Without you having to restore it using `Signal.trap("TERM", old_handler)`

```ruby
Signal.trap("TERM", "IGNORE")
 => "DEFAULT"

SignalActionHandler.info["TERM"]
 => "IGNORE"
```

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'signal_action_handler'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install signal_action_handler

## Development

After checking out the repo, run

    $ bundle install
    $ rake install

You can also run `bundle console` for an interactive prompt that will allow you to experiment.

The gem has has been purely written in C, as extention for ruby.

## Test
    $ bundle exec rspec

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/shayonj/signal_action_handler.
