# Third party libraries

## Clipper

- Upstream: https://sourceforge.net/projects/polyclipping/
- Version: 10.0.0 r539 (sandbox)
- License: Boost Software License - Version 1.0

### Changes

- `Clipper.GetBounds` bug temporarily fixed:
    - https://sourceforge.net/p/polyclipping/bugs/176/
- Workaround for ill-formed `Clipper.PolyTree`, simply replaced with `Clipper.PolyPath`: 
    - https://sourceforge.net/p/polyclipping/bugs/177/
- Disabled exceptions (similarly to Godot's `clipper-no-exceptions.patch`)
- Removed Windows-specific debugging calls.

See [`clipper.10.0.0-r539-no-except.patch`](clipper/clipper.10.0.0-r539-no-except.patch)
file for the exact changes.
