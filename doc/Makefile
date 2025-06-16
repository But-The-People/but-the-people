production-tree.pdf: production-tree.dot
	dot -Tpdf production-tree.dot > production-tree.pdf
production-tree.dot: production-tree.rb
	ruby production-tree.rb > production-tree.dot
